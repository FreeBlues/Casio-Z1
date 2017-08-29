#include <stdio.h>
#include "z1.h"

#if defined(I86_LITTLEENDIAN)
#	define LOW(x)	((uint8 *)&(x) + 0)
#	define HIGH(x)	((uint8 *)&(x) + 1)
#else
#	define LOW(x)	((uint8 *)&(x) + 1)
#	define HIGH(x)	((uint8 *)&(x) + 0)
#endif

uint8 i86inp8(const I86stat *i86, uint16 port)
{
	Z1stat *z1 = i86->i.tag;
	uint16 v;

	/*
	printf("IO IN %04x\n", port);
	*/

	switch(port) {
	case 0x003e: /* ? */
		return 0x20;
	case 0x005a: /* バッテリー容量 */
		return 0x04;
	/*
	case 0x0082:
		return 0x00;
	case 0x0083:
		return 0x08;
	case 0x0086:
		return 0x00;
	case 0x0087:
		return 0x08;
	case 0x00a2:
		return 0x0a;
	case 0x00a3:
		return 0x08;
	*/
	case 0x0202:
	case 0x0203:
		/*
		printf(
		"KEY %04x:"
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x "
		"%04x\n",
		z1->key.strobe,
		z1->key.matrix[0],
		z1->key.matrix[1],
		z1->key.matrix[2],
		z1->key.matrix[3],
		z1->key.matrix[4],
		z1->key.matrix[5],
		z1->key.matrix[6],
		z1->key.matrix[7],
		z1->key.matrix[8],
		z1->key.matrix[9],
		z1->key.matrix[10]
		);
		*/
		v =
		(z1->key.strobe & 0x0001 ? z1->key.matrix[0]: 0) |
		(z1->key.strobe & 0x0002 ? z1->key.matrix[1]: 0) |
		(z1->key.strobe & 0x0004 ? z1->key.matrix[2]: 0) |
		(z1->key.strobe & 0x0008 ? z1->key.matrix[3]: 0) |
		(z1->key.strobe & 0x0010 ? z1->key.matrix[4]: 0) |
		(z1->key.strobe & 0x0020 ? z1->key.matrix[5]: 0) |
		(z1->key.strobe & 0x0040 ? z1->key.matrix[6]: 0) |
		(z1->key.strobe & 0x0080 ? z1->key.matrix[7]: 0) |
		(z1->key.strobe & 0x0100 ? z1->key.matrix[8]: 0) |
		(z1->key.strobe & 0x0200 ? z1->key.matrix[9]: 0) |
		(z1->key.strobe & 0x0400 ? z1->key.matrix[10]: 0);
		if(!v)
			v = 0x8000;
		return (port == 0x0202 ? v & 0xff: v >> 8);
	default:
		/*
		printf("IO IN %04x\n", port);
		*/
		return 0;
	}
}

void i86out8(I86stat *i86, uint16 port, uint8 x)
{
	Z1stat *z1 = i86->i.tag;

	/*
	printf("IO OUT %04x,%02x\n", port, x);
	*/

	switch(port) {
	case 0x0002:
		*LOW(z1->eoi) = x;
		break;
	case 0x0003:
		*HIGH(z1->eoi) = x;
		break;
	case 0x0036:
		*LOW(z1->timer0.control) = x;
		break;
	case 0x0037:
		*HIGH(z1->timer0.control) = x;
		break;
	case 0x003e:
		*LOW(z1->timer1.control) = x;
		break;
	case 0x003f:
		*HIGH(z1->timer1.control) = x;
		break;
	case 0x0046:
		*LOW(z1->timer2.control) = x;
		break;
	case 0x0047:
		*HIGH(z1->timer2.control) = x;
		break;
	case 0x00b8:
		z1->io_b8 = x;
		break;
	case 0x0200:
		*LOW(z1->key.strobe) = x;
		break;
	case 0x0201:
		*HIGH(z1->key.strobe) = x;
		break;
	case 0x0220: /* ?? */
		/*
		printf("OUT 220H %02x\n", x);
		printf("X=");
		for(i = 0x400; i <= 0x40f; i++)
			printf("%02x ", i86->m[i]);
		printf("\n");
		printf("Y=");
		for(i = 0x410; i <= 0x41f; i++)
			printf("%02x ", i86->m[i]);
		printf("\n");
		printf("W=");
		for(i = 0x420; i <= 0x42e; i++)
			printf("%02x ", i86->m[i]);
		printf("\n");
		fflush(stdout);

		if(x == 0x99)
			i86->m[0x406] = 1;
		if(i86read8(i86, 0, 0x400) != 0)
			i86->m[0x400] = 0;
		if(i86read8(i86, 0, 0x405) != 0)
			i86->m[0x405] = 0;
		*/

		/*
		for(i = 0x400; i < 0x420; i++)
			i86write8(i86, 0, i, 0);
		i86write8(i86, 0, 0x406, rand() % 10);
		*/
		break;
	case 0x0221:
		/*
		printf("OUT 221H %02x\n", x);
		printf("X=");
		for(i = 0x400; i <= 0x40f; i++)
			printf("%02x ", i86->m[i]);
		printf("\n");
		printf("Y=");
		for(i = 0x410; i <= 0x41f; i++)
			printf("%02x ", i86->m[i]);
		printf("\n");
		printf("W=");
		for(i = 0x420; i <= 0x42e; i++)
			printf("%02x ", i86->m[i]);
		printf("\n");
		fflush(stdout);
		*/
		/*
		if(x == 0x10) {
			for(i = 0x400; i <= 0x40f; i++)
				i86write8(i86, 0, i, 0);
			for(i = 0x410; i <= 0x41f; i++)
				i86write8(i86, 0, i, 0);
		}
		*/
		break;
	default:
		/*
		printf("IO OUT %04x,%02x\n", port, x);
		*/
		break;
	}
}

uint16 i86inp16(const I86stat *i86, uint16 port)
{
	return ((uint16 )i86inp8(i86, port + 1) << 8) | i86inp8(i86, port);
}

void i86out16(I86stat *i86, uint16 port, uint16 x)
{
	i86out8(i86, port + 1, x >> 8);
	i86out8(i86, port, x & 0xff);
}

/* eof */
