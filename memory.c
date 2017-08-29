#include <stdio.h>
#include "z1.h"

static inline uint8 readVram(const I86stat *cpu, int p)
{
	Z1stat *z1 = cpu->i.tag;

	if(p & 1)
		return 0;
	else
		return z1->lcd.reg;
}

static inline void pset(uint8 *vram, int x, int y, int pix)
{
	if(pix)
		vram[y * (LCD_WIDTH / 8) + (x / 8)] |= (0x80 >> (x % 8));
	else
		vram[y * (LCD_WIDTH / 8) + (x / 8)] &= ~(0x80 >> (x % 8));
}

static inline void writeVram(I86stat *cpu, int p, uint8 v)
{
	Z1stat *z1 = cpu->i.tag;
	int x, y;

	if(p & 1) {
		switch(z1->lcd.reg & 7) {
		case 0:
			if(z1->lcd.fcr & 0x40) {
				if(6 <= z1->lcd.xar && z1->lcd.xar < VRAM_WIDTH && z1->lcd.yar < VRAM_HEIGHT) {
					/*
					printf(
					"x=%d,y=%d %c%c%c%c%c%c%c%c\n",
					z1->lcd.xar,
					z1->lcd.yar,
					(v & 0x80 ? '#': '_'),
					(v & 0x40 ? '#': '_'),
					(v & 0x20 ? '#': '_'),
					(v & 0x10 ? '#': '_'),
					(v & 0x08 ? '#': '_'),
					(v & 0x04 ? '#': '_'),
					(v & 0x02 ? '#': '_'),
					(v & 0x01 ? '#': '_')
					);
					*/
					x = (z1->lcd.yar / 32) * 96 + (z1->lcd.xar - 6) * 6;
					y = (z1->lcd.yar % 32);
					pset(z1->lcd.vram, x + 0, y, v & 0x20);
					pset(z1->lcd.vram, x + 1, y, v & 0x10);
					pset(z1->lcd.vram, x + 2, y, v & 0x08);
					pset(z1->lcd.vram, x + 3, y, v & 0x04);
					pset(z1->lcd.vram, x + 4, y, v & 0x02);
					pset(z1->lcd.vram, x + 5, y, v & 0x01);
				}
			} else {
				if(4 <= z1->lcd.xar && z1->lcd.xar < VRAM_WIDTH && z1->lcd.yar < VRAM_HEIGHT) {
					/*
					printf(
					"x=%d,y=%d %c%c%c%c%c%c%c%c\n",
					z1->lcd.xar,
					z1->lcd.yar,
					(v & 0x80 ? '#': '_'),
					(v & 0x40 ? '#': '_'),
					(v & 0x20 ? '#': '_'),
					(v & 0x10 ? '#': '_'),
					(v & 0x08 ? '#': '_'),
					(v & 0x04 ? '#': '_'),
					(v & 0x02 ? '#': '_'),
					(v & 0x01 ? '#': '_')
					);
					*/
					x = (z1->lcd.yar / 32) * 96 + (z1->lcd.xar - 4) * 8;
					y = (z1->lcd.yar % 32);
					pset(z1->lcd.vram, x - 4, y, v & 0x80);
					pset(z1->lcd.vram, x - 3, y, v & 0x40);
					pset(z1->lcd.vram, x - 2, y, v & 0x20);
					pset(z1->lcd.vram, x - 1, y, v & 0x10);
					pset(z1->lcd.vram, x + 0, y, v & 0x08);
					pset(z1->lcd.vram, x + 1, y, v & 0x04);
					pset(z1->lcd.vram, x + 2, y, v & 0x02);
					pset(z1->lcd.vram, x + 3, y, v & 0x01);
				}
			}
			if(z1->lcd.fcr & 0x80)
				z1->lcd.xar++;
			else
				z1->lcd.yar++;
			break;
		case 1:
			z1->lcd.xar = v;
			/*
			printf("x=%d,y=%d\n", z1->lcd.xar, z1->lcd.yar);
			*/
			break;
		case 2:
			z1->lcd.yar = v;
			/*
			printf("x=%d,y=%d\n", z1->lcd.xar, z1->lcd.yar);
			*/
			break;
		case 3:
			z1->lcd.fcr = v;
			break;
		case 4:
			break;
		case 5:
			break;
		}
	} else
		z1->lcd.reg = v;
}

uint8 i86read8(const I86stat *cpu, uint16 seg, uint16 off)
{
	int p = (((int )seg << 4) + off) & 0xfffff;
	/*
	if(0x400 <= p && p <= 0x40f)
		printf("READ IP=%04x p=%04x v=%02x\n", cpu->r16.ip, p, cpu->m[p]);
	*/

	if(p < 0x40000)
		return cpu->m[p]; /* RAM */
	else if(p < 0xa0000)
		return p & 0xff;
	else if(p < 0xb0000)
		return readVram(cpu, p);
	else if(p < 0xe0000)
		return p & 0xff;
	else
		return cpu->m[p - 0xe0000 + 0x40000]; /* ROM */
}

void i86write8(I86stat *cpu, uint16 seg, uint16 off, uint8 v)
{
	int p = (((int )seg << 4) + off) & 0xfffff;

	/*
	if(0x400 <= p && p <= 0x40f)
		printf("WRITE IP=%04x p=%04x v=%02x\n", cpu->r16.ip, p, v);
	*/

	if(p < 0x40000)
		cpu->m[p] = v; /* RAM */
	else if(p < 0xa0000)
		return;
	else if(p < 0xb0000)
		writeVram(cpu, p, v);
}

uint16 i86read16(const const I86stat *cpu, uint16 seg, uint16 off)
{
	return ((uint16 )i86read8(cpu, seg, off + 1) << 8) + (uint16 )i86read8(cpu, seg, off);
}

void i86write16(I86stat *cpu, uint16 seg, uint16 off, uint16 v)
{
	i86write8(cpu, seg, off + 0, v & 0xff);
	i86write8(cpu, seg, off + 1, v >> 8);
}

/* eof */
