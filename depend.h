#ifndef DEPEND_H
#define DEPEND_H

#include <stdio.h>
#include "z1.h"
#include "SDL.h"

EXTERN uint8 keyConv[]
#if defined(DEF_GLOBAL)
= {
	/* 0 */
	0,	/* SDLK_NONE */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	
	/* 8 */
	ZKEY_BS,	/* SDLK_BACKSPACE */
	ZKEY_TAB,	/* SDLK_TAB */
	0,
	0,
	ZKEY_CLS,	/* SDLK_CLEAR */
	ZKEY_RETURN,	/* SDLK_RETURN */
	0,
	0,

	/* 16 */
	0,
	0,
	0,
	ZKEY_BRK,	/* SDLK_PAUSE */
	0,
	0,
	0,
	0,

	/* 24 */
	0,
	0,
	0,
	ZKEY_OFF,	/* SDLK_ESCAPE */
	0,
	0,
	0,
	0,

	/* 32 */
	ZKEY_SPC,	/* SDLK_SPACE */
	0,	/* SDLK_EXCLAIM */
	0,	/* SDLK_QUOTEDBL */
	0,	/* SDLK_HASH */
	0,	/* SDLK_DOLLAR */
	0,
	0,	/* SDLK_AMPERSAND */
	0,	/* SDLK_QUOTE */

	/* 40 */
	ZKEY_LPAREN,	/* SDLK_LEFTPAREN */
	ZKEY_RPAREN,	/* SDLK_RIGHTPAREN */
	ZKEY_ASTER,	/* SDLK_ASTERISK */
	ZKEY_PLUS,	/* SDLK_PLUS */
	ZKEY_COMMA,	/* SDLK_COMMA */
	ZKEY_MINUS,	/* SDLK_MINUS */
	ZKEY_PERIOD,	/* SDLK_PERIOD */
	ZKEY_SLASH,	/* SDLK_SLASH */

	/* 48 */
	ZKEY_0,	/* SDLK_0 */
	ZKEY_1,	/* SDLK_1 */
	ZKEY_2,	/* SDLK_2 */
	ZKEY_3,	/* SDLK_3 */
	ZKEY_4,	/* SDLK_4 */
	ZKEY_5,	/* SDLK_5 */
	ZKEY_6,	/* SDLK_6 */
	ZKEY_7,	/* SDLK_7 */

	/* 56 */
	ZKEY_8,	/* SDLK_8 */
	ZKEY_9,	/* SDLK_9 */
	ZKEY_COLON,	/* SDLK_COLON */
	ZKEY_SEMICOLON,	/* SDLK_SEMICOLON */
	0,	/* SDLK_LESS */
	ZKEY_EQUAL,	/* SDLK_EQUALS */
	0,	/* SDLK_GREATER */
	0,	/* SDLK_QUESTION */

	/* 64 */
	0,	/* SDLK_AT */
	0,
	0,
	0,
	0,
	0,
	0,
	0,

	/* 72 */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,

	/* 80 */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,

	/* 88 */
	0,
	0,
	0,
	ZKEY_LPAREN,	/* SDLK_LEFTBRACKET */
	ZKEY_SLASH,	/* SDLK_BACKSLASH */
	ZKEY_RPAREN,	/* SDLK_RIGHTBRACKET */
	0,	/* SDLK_CARET */
	0,	/* SDLK_UNDERSCORE */

	/* 96 */
	0,	/* SDLK_BACKQUOTE */
	ZKEY_A,	/* SDLK_A */
	ZKEY_B,	/* SDLK_B */
	ZKEY_C,	/* SDLK_C */
	ZKEY_D,	/* SDLK_D */
	ZKEY_E,	/* SDLK_E */
	ZKEY_F,	/* SDLK_F */
	ZKEY_G,	/* SDLK_G */

	/* 104 */
	ZKEY_H,	/* SDLK_H */
	ZKEY_I,	/* SDLK_I */
	ZKEY_J,	/* SDLK_J */
	ZKEY_K,	/* SDLK_K */
	ZKEY_L,	/* SDLK_L */
	ZKEY_M,	/* SDLK_M */
	ZKEY_N,	/* SDLK_N */
	ZKEY_O,	/* SDLK_O */

	/* 112 */
	ZKEY_P,	/* SDLK_P */
	ZKEY_Q,	/* SDLK_Q */
	ZKEY_R,	/* SDLK_R */
	ZKEY_S,	/* SDLK_S */
	ZKEY_T,	/* SDLK_T */
	ZKEY_U,	/* SDLK_U */
	ZKEY_V,	/* SDLK_V */
	ZKEY_W,	/* SDLK_W */

	/* 120 */
	ZKEY_X,	/* SDLK_X */
	ZKEY_Y,	/* SDLK_Y */
	ZKEY_Z,	/* SDLK_Z */
	0,
	0,
	0,
	0,
	ZKEY_BS,	/* SDLK_BACKSPACE */

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	
	/* 256 */
	ZKEY_0,	/* SDLK_0 */
	ZKEY_1,	/* SDLK_1 */
	ZKEY_2,	/* SDLK_2 */
	ZKEY_3,	/* SDLK_3 */
	ZKEY_4,	/* SDLK_4 */
	ZKEY_5,	/* SDLK_5 */
	ZKEY_6,	/* SDLK_6 */
	ZKEY_7,	/* SDLK_7 */

	/* 264 */
	ZKEY_8,	/* SDLK_8 */
	ZKEY_9,	/* SDLK_9 */
	ZKEY_PERIOD,	/* SDLK_KP_PERIOD */
	ZKEY_SLASH,	/* SDLK_KP_DEVIDE */
	ZKEY_ASTER,	/* SDLK_MULTIPLY */
	ZKEY_MINUS,	/* SDLK_MINUS */
	ZKEY_PLUS,	/* SDLK_PLUS */
	ZKEY_RETURN,	/* SDLK_ENTER */

	/* 272 */
	ZKEY_EQUAL,	/* SDLK_KP_EQUAL */
	ZKEY_UP,	/* SDLK_UP */
	ZKEY_DOWN,	/* SDLK_DOWN */
	ZKEY_RIGHT,	/* SDLK_RIGHT */
	ZKEY_LEFT,	/* SDLK_LEFT */
	ZKEY_INS,	/* SDLK_INSERT */
	ZKEY_CLS,	/* SDLK_HOME */
	0,

	/* 280 */
	0,	/* SDLK_PAGEUP */
	0,	/* SDLK_PAGEDOWN */
	0,	/* SDLK_F1 */
	0,	/* SDLK_F2 */
	0,	/* SDLK_F3 */
	0,	/* SDLK_F4 */
	0,	/* SDLK_F5 */
	0,	/* SDLK_F6 */

	/* 288 */
	0,	/* SDLK_F7 */
	0,	/* SDLK_F8 */
	0,	/* SDLK_F9 */
	0,	/* SDLK_F10 */
	0,	/* SDLK_F11 */
	0,	/* SDLK_F12 */
	0,	/* SDLK_F13 */
	0,	/* SDLK_F14 */

	/* 296 */
	0,	/* SDLK_F15 */
	0,
	0,
	0,
	0,	/* SDLK_NUMLOCK */
	ZKEY_CAPS,	/* SDLK_CAPSLOCK */
	0,	/* SDLK_SCROLLOCK */
	ZKEY_2NDF,	/* SDLK_RSHIFT */

	/* 304 */
	0,	/* SDLK_LSHIFT */
	0,	/* SDLK_RCTRL */
	0,	/* SDLK_LCTRL */
	0,	/* SDLK_RLAT */
	ZKEY_CAPS,	/* SDLK_LALT */
	0,	/* SDLK_RMETA */
	0,	/* SDLK_LMETA */
	0,	/* SDLK_LSUPER */

	/* 312 */
	0,	/* SDLK_RSUPER */
	0,	/* SDLK_MODE */
	0,	/* SDLK_COMPOSE */
	0,	/* SDLK_HELP */
	0,	/* SDLK_PRINT */
	0,	/* SDLK_SYSREQ */
	ZKEY_BRK,	/* SDLK_BREAK */
	0,	/* SDLK_MENU */

	/* 320 */
	ZKEY_BRK,	/* SDLK_POWER */
	0,	/* SDLK_EURO */
	0	/* SDLK_UNDO */
}
#endif
;

#endif

/* eof */
