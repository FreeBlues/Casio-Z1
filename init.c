#include <stdio.h>
#include "z1.h"

const static OptTable tableYesNo[] = {
	{ "y", TRUE },
	{ "1", TRUE },
	{ "n", FALSE },
	{ "0", FALSE },
	{ NULL, 0 }
};

const static OptTable tableKey[] = {
	{ "none", 0 },
	{ "backspace", SDLK_BACKSPACE },
	{ "tab", SDLK_TAB },
	{ "clear", SDLK_CLEAR },
	{ "return", SDLK_RETURN },
	{ "enter", SDLK_RETURN },
	{ "pause", SDLK_PAUSE },
	{ "escape", SDLK_ESCAPE },
	{ "space", SDLK_SPACE },
	{ "!", SDLK_EXCLAIM },
	{ "\"", SDLK_QUOTEDBL },
	{ "hash", SDLK_HASH },
	{ "sharp", SDLK_HASH },
	{ "$", SDLK_DOLLAR },
	{ "&", SDLK_AMPERSAND },
	{ "+", SDLK_PLUS },
	{ ",", SDLK_COMMA },
	{ "-", SDLK_MINUS },
	{ ".", SDLK_PERIOD },
	{ "/", SDLK_SLASH },
	{ "0", SDLK_0 },
	{ "1", SDLK_1 },
	{ "2", SDLK_2 },
	{ "3", SDLK_3 },
	{ "4", SDLK_4 },
	{ "5", SDLK_5 },
	{ "6", SDLK_6 },
	{ "7", SDLK_7 },
	{ "8", SDLK_8 },
	{ "9", SDLK_9 },
	{ ":", SDLK_COLON },
	{ ";", SDLK_SEMICOLON },
	{ "=", SDLK_EQUALS },
	{ ">", SDLK_GREATER },
	{ "?", SDLK_QUESTION },
	{ "[", SDLK_LEFTBRACKET },
	{ "\\", SDLK_BACKSLASH },
	{ "]", SDLK_RIGHTBRACKET },
	{ "^", SDLK_CARET },
	{ "_", SDLK_UNDERSCORE },
	{ "`", SDLK_BACKQUOTE },
	{ "@", SDLK_AT},
	{ "a", SDLK_a },
	{ "b", SDLK_b },
	{ "c", SDLK_c },
	{ "d", SDLK_d },
	{ "e", SDLK_e },
	{ "f", SDLK_f },
	{ "g", SDLK_g },
	{ "h", SDLK_h },
	{ "i", SDLK_i },
	{ "j", SDLK_j },
	{ "k", SDLK_k },
	{ "l", SDLK_l },
	{ "m", SDLK_m },
	{ "n", SDLK_n },
	{ "o", SDLK_o },
	{ "p", SDLK_p },
	{ "q", SDLK_q },
	{ "r", SDLK_r },
	{ "s", SDLK_s },
	{ "t", SDLK_t },
	{ "u", SDLK_u },
	{ "v", SDLK_v },
	{ "w", SDLK_w },
	{ "x", SDLK_x },
	{ "y", SDLK_y },
	{ "z", SDLK_z },
	{ "delete"   , SDLK_DELETE },
	{ "n0", SDLK_KP0 },
	{ "n1", SDLK_KP1 },
	{ "n2", SDLK_KP2 },
	{ "n3", SDLK_KP3 },
	{ "n4", SDLK_KP4 },
	{ "n5", SDLK_KP5 },
	{ "n6", SDLK_KP6 },
	{ "n7", SDLK_KP7 },
	{ "n8", SDLK_KP8 },
	{ "n9", SDLK_KP9 },
	{ "n.", SDLK_KP_PERIOD },
	{ "n/", SDLK_KP_DIVIDE },
	{ "n*", SDLK_KP_MULTIPLY },
	{ "n-", SDLK_KP_MINUS },
	{ "n+", SDLK_KP_PLUS },
	{ "nreturn"  , SDLK_KP_ENTER },
	{ "nenter"   , SDLK_KP_ENTER },
	{ "n=", SDLK_KP_EQUALS },
	{ "f1", SDLK_F1 },
	{ "f2", SDLK_F2 },
	{ "f3", SDLK_F3 },
	{ "f4", SDLK_F4 },
	{ "f5", SDLK_F5 },
	{ "f6", SDLK_F6 },
	{ "f7", SDLK_F7 },
	{ "f8", SDLK_F8 },
	{ "f9", SDLK_F9 },
	{ "f10", SDLK_F10 },
	{ "f11", SDLK_F11 },
	{ "f12", SDLK_F12 },
	{ "f13", SDLK_F13 },
	{ "f14", SDLK_F14 },
	{ "f15", SDLK_F15 },
	{ "up", SDLK_UP},
	{ "down", SDLK_DOWN },
	{ "right", SDLK_RIGHT },
	{ "left", SDLK_LEFT },
	{ "insert", SDLK_INSERT },
	{ "home", SDLK_HOME },
	{ "end" , SDLK_END },
	{ "pageup", SDLK_PAGEUP },
	{ "pagedown" , SDLK_PAGEDOWN },
	{ "numlock", SDLK_NUMLOCK },
	{ "capslock" , SDLK_CAPSLOCK },
	{ "scrollock", SDLK_SCROLLOCK },
	{ "rshift", SDLK_RSHIFT},
	{ "lshift", SDLK_LSHIFT},
	{ "rctrl", SDLK_RCTRL },
	{ "lctrl", SDLK_LCTRL },
	{ "ralt", SDLK_RALT },
	{ "lalt", SDLK_LALT },
	{ "lsuper", SDLK_LSUPER },
	{ "rsuper", SDLK_RSUPER },
	{ "mode", SDLK_MODE},
	{ "compose", SDLK_COMPOSE },
	{ "help", SDLK_HELP},
	{ "print", SDLK_PRINT },
	{ "sysreq", SDLK_SYSREQ},
	{ "break", SDLK_BREAK },
	{ "menu", SDLK_MENU},
	{ "power", SDLK_POWER },
	{ "euro", SDLK_EURO },
	/*{ "undo", SDLK_UNDO },*/
	{ NULL, 0 }
};

static OptTable tableZkey[] = {
	{ "brk", ZKEY_BRK },
	{ "k02", 0x02 },
	{ "k03", 0x03 },
	{ "k04", 0x04 },
	{ "k05", 0x05 },
	{ "k06", 0x06 },
	{ "k07", 0x07 },
	{ "k08", 0x08 },
	{ "k09", 0x09 },
	{ "k0a", 0x0a },
	{ "tab", ZKEY_TAB },
	{ "q", ZKEY_Q },
	{ "allreset", ZKEY_ALLRESET },
	{ "a", ZKEY_A },
	{ "caps", ZKEY_CAPS },
	{ "z", ZKEY_Z },
	{ "w", ZKEY_W },
	{ "e", ZKEY_E },
	{ "s", ZKEY_S },
	{ "d", ZKEY_D },
	{ "x", ZKEY_X },
	{ "c", ZKEY_C },
	{ "srch", ZKEY_SRCH },
	{ "in", ZKEY_IN },
	{ "r", ZKEY_R },
	{ "t", ZKEY_T },
	{ "f", ZKEY_F },
	{ "g", ZKEY_G },
	{ "v", ZKEY_V },
	{ "b", ZKEY_B },
	{ "out", ZKEY_OUT },
	{ "calc", ZKEY_CALC },
	{ "y", ZKEY_Y },
	{ "u", ZKEY_U },
	{ "h", ZKEY_H },
	{ "j", ZKEY_J },
	{ "n", ZKEY_N },
	{ "m", ZKEY_M },
	{ "spc", ZKEY_SPC },
	{ "=", ZKEY_EQUAL },
	{ "i", ZKEY_I },
	{ "o", ZKEY_O },
	{ "k", ZKEY_K },
	{ "l", ZKEY_L },
	{ ",", ZKEY_COMMA },
	{ "ins", ZKEY_INS },
	{ "left", ZKEY_LEFT },
	{ "down", ZKEY_DOWN },
	{ "p", ZKEY_P },
	{ "rshift", ZKEY_2NDF },
	{ ";", ZKEY_SEMICOLON },
	{ ":", ZKEY_COLON },
	{ "up", ZKEY_UP },
	{ "del", ZKEY_DEL },
	{ "right", ZKEY_RIGHT },
	{ "0", ZKEY_0 },
	{ "menu", ZKEY_MENU },
	{ "log", ZKEY_LOG },
	{ "mr", ZKEY_MR },
	{ "7", ZKEY_7 },
	{ "4", ZKEY_4 },
	{ "1", ZKEY_1 },
	{ ".", ZKEY_PERIOD },
	{ "ee", ZKEY_EE },
	{ "return", ZKEY_RETURN },
	{ "cal", ZKEY_CAL },
	{ "ln", ZKEY_LN },
	{ "m+", ZKEY_MPLUS },
	{ "8", ZKEY_8 },
	{ "5", ZKEY_5 },
	{ "2", ZKEY_2 },
	{ "3", ZKEY_3 },
	{ "+", ZKEY_PLUS },
	{ "-", ZKEY_MINUS },
	{ "degr", ZKEY_DEGR },
	{ "sin", ZKEY_SIN },
	{ "(", ZKEY_LPAREN },
	{ ")", ZKEY_RPAREN },
	{ "9", ZKEY_9 },
	{ "6", ZKEY_6 },
	{ "*", ZKEY_ASTER },
	{ "/", ZKEY_SLASH },
	{ "bs", ZKEY_BS },
	{ "sqrt", ZKEY_SQRT },
	{ "x2", ZKEY_X2 },
	{ "eng", ZKEY_ENG },
	{ "cls", ZKEY_CLS },
	{ "cos", ZKEY_COS },
	{ "^", ZKEY_HAT },
	{ "ans", ZKEY_ANS },
	{ "tan", ZKEY_TAN },
	{ "off", ZKEY_OFF },
	{ "trace", ZKEY_DEBUG },
	{ NULL, 0 }
};

int init(Z1stat *z, int argc, char *argv[])
{
	Conf conf[256];
	const OptTable *p;

	memset(z, 0, sizeof(*z));

	if(getConfig(conf, sizeof(conf) / sizeof(conf[0]), "z1config", argc, argv) == NULL)
		return FALSE;

	/*
	setHomeDir(pathROM, getOptText(conf, "rom_dir", ""));
	strcat(pathROM, "/rom.txt");
	setHomeDir(pathRAM, getOptText(conf, "ram_path", "ram.bin"));
	*/
	setHomeDir(pathROM, getOptText(conf, "rom_dir", ""));
	strcat(pathROM, "/romz1.bin");
	setHomeDir(pathRAM, getOptText(conf, "ram_path", "ram.bin"));

	for(p = tableZkey; p->string != NULL; p++)
		keyConv[getOptTable(conf, p->string, tableKey, 0)] = p->value;
	z->cpu.i.trace = getOptTable(conf, "debug", tableYesNo, FALSE);

	return TRUE;
}

/* eof */