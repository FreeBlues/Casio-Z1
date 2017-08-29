#include <stdio.h>
#include "z1.h"

const static SDL_VideoInfo *video;
static SDL_Surface *screen;
static Uint32 pixMap[2];

inline static void _pset(int x, int y, int dot)
{
	Uint32 pix = pixMap[dot ? 1: 0];
	Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + screen->format->BytesPerPixel * x;

	switch(screen->format->BytesPerPixel) {
	case 1:
		*p = (Uint8 )pix;
		break;
	case 2:
		*(Uint16 *)p = (Uint16 )pix;
		break;
	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
			p[0] = (pix >> 16) & 0xff;
			p[1] = (pix >> 8) & 0xff;
			p[2] = pix & 0xff;
		} else {
			p[0] = pix & 0xff;
			p[1] = (pix >> 8) & 0xff;
			p[2] = (pix >> 16) & 0xff;
		}
		break;
	case 4:
		*(Uint32 *)p = pix;
		break;
	}
}
inline static void pset(int x, int y, int dot)
{
	int zoom = 3;

	_pset(x * zoom + 0, y * zoom + 0, dot);
	_pset(x * zoom + 1, y * zoom + 0, dot);
	_pset(x * zoom + 2, y * zoom + 0, dot);
	_pset(x * zoom + 0, y * zoom + 1, dot);
	_pset(x * zoom + 1, y * zoom + 1, dot);
	_pset(x * zoom + 2, y * zoom + 1, dot);
	_pset(x * zoom + 0, y * zoom + 2, dot);
	_pset(x * zoom + 1, y * zoom + 2, dot);
	_pset(x * zoom + 2, y * zoom + 2, dot);
}

void updateLCD(Z1stat *z1)
{
	int lock, x, y;
	const uint8 *p = z1->lcd.vram;

	if((lock = SDL_MUSTLOCK(screen)))
		if(SDL_LockSurface(screen) < 0)
			return;

	for(y = 0; y < LCD_HEIGHT; y++)
		for(x = 0; x < LCD_WIDTH; x += 8) {
			pset(x + 0, y, *p & 0x80);
			pset(x + 1, y, *p & 0x40);
			pset(x + 2, y, *p & 0x20);
			pset(x + 3, y, *p & 0x10);
			pset(x + 4, y, *p & 0x08);
			pset(x + 5, y, *p & 0x04);
			pset(x + 6, y, *p & 0x02);
			pset(x + 7, y, *p & 0x01);
			p++;
		}

	if(lock)
		SDL_UnlockSurface(screen);
	SDL_UpdateRect(screen, 0, 0, 0, 0);
}

inline static int pressKey(Z1stat *z1, uint8 key)
{
	if(key == 0)
		return -1;
	if(key == ZKEY_DEBUG) {
		z1->cpu.i.trace = !z1->cpu.i.trace;
		return -1;
	}
	if(key == ZKEY_OFF)
		return 0x03;
	
	/*
	printf("key=%x\n", key);
	*/
	key--;
	z1->key.matrix[key / 0x10] |= (1 << (key % 0x10));
	return 0x0c;
}

inline static int releaseKey(Z1stat *z1, uint8 key)
{
	if(key == 0)
		return -1;
	if(key == ZKEY_DEBUG)
		return -1;
	if(key == ZKEY_OFF)
		return 0x03;
		
	key--;
	z1->key.matrix[key / 0x10] &= ~(1 << (key % 0x10));
	return 0x0c;
}

int updateKey(Z1stat *z1)
{
	SDL_Event e;
	int intr;

	while(SDL_PollEvent(&e)) {
		switch(e.type) {
		case SDL_KEYDOWN:
			if((intr = pressKey(z1, keyConv[e.key.keysym.sym])) >= 0)
				return intr;
			break;
		case SDL_KEYUP:
			if((intr = releaseKey(z1, keyConv[e.key.keysym.sym])) >= 0)
				return intr;
			break;
		case SDL_QUIT:
			exit(0);
			break;
		}
	}
	return -1;
}

void delay(int interval)
{
	static Uint32 last = 0, left;
	Uint32 now;

	now = SDL_GetTicks();
	if(last + interval > now) {
		left = last + interval - now;
		SDL_Delay(left);
		last = now + left;
	} else
		last = now;
}

int initDepend(void)
{
	int zoom = 3;

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) {
		fprintf(stderr, "SDL_Init fail. %s\n", SDL_GetError());
		return FALSE;
	}
	atexit(SDL_Quit);
	if((video = SDL_GetVideoInfo()) == NULL) {
		fprintf(stderr, "SDL_GetVideoInfo fail. %s\n", SDL_GetError());
		return FALSE;
	}
	SDL_WM_SetCaption("Z-1/FX-890P", NULL);
	if((screen = SDL_SetVideoMode(192 * zoom, 32 * zoom, video->vfmt->BitsPerPixel, SDL_HWSURFACE)) == NULL) {
		fprintf(stderr, "SDL_SetVideoMode fail. %s", SDL_GetError());
		return FALSE;
	}

	pixMap[0] = SDL_MapRGB(screen->format, 0xaa, 0xdd, 0xbb);
	pixMap[1] = SDL_MapRGB(screen->format, 0x00, 0x22, 0x11);

	return TRUE;
}

/* eof */
