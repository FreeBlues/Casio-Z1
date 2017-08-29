#ifndef Z1_H
#define Z1_H

#include <stdio.h>
#include <limits.h>
#include "i80x86.h"
#include "conf.h"

#define FALSE	0
#define TRUE	1

#define VRAM_HEIGHT	65
#define VRAM_WIDTH	32
#define LCD_HEIGHT	32
#define LCD_WIDTH	192

#define ZKEY_BRK	0x01
#define ZKEY_TAB	0x12
#define ZKEY_Q	0x13
#define ZKEY_ALLRESET	0x14
#define ZKEY_A	0x15
#define ZKEY_CAPS	0x16
#define ZKEY_Z	0x17
#define ZKEY_W	0x22
#define ZKEY_E	0x23
#define ZKEY_S	0x24
#define ZKEY_D	0x25
#define ZKEY_X	0x26
#define ZKEY_C	0x27
#define ZKEY_SRCH	0x28
#define ZKEY_IN	0x29
#define ZKEY_R	0x32
#define ZKEY_T	0x33
#define ZKEY_F	0x34
#define ZKEY_G	0x35
#define ZKEY_V	0x36
#define ZKEY_B	0x37
#define ZKEY_OUT	0x38
#define ZKEY_CALC	0x39
#define ZKEY_Y	0x42
#define ZKEY_U	0x43
#define ZKEY_H	0x44
#define ZKEY_J	0x45
#define ZKEY_N	0x46
#define ZKEY_M	0x47
#define ZKEY_SPC	0x48
#define ZKEY_EQUAL	0x49
#define ZKEY_I	0x52
#define ZKEY_O	0x53
#define ZKEY_K	0x54
#define ZKEY_L	0x55
#define ZKEY_COMMA	0x56
#define ZKEY_INS	0x57
#define ZKEY_LEFT	0x58
#define ZKEY_DOWN	0x59
#define ZKEY_P	0x62
#define ZKEY_2NDF	0x63
#define ZKEY_SEMICOLON	0x64
#define ZKEY_COLON	0x65
#define ZKEY_UP	0x66
#define ZKEY_DEL	0x67
#define ZKEY_RIGHT	0x68
#define ZKEY_0	0x69
#define ZKEY_MENU	0x72
#define ZKEY_LOG	0x73
#define ZKEY_MR	0x74
#define ZKEY_7	0x75
#define ZKEY_4	0x76
#define ZKEY_1	0x77
#define ZKEY_PERIOD	0x78
#define ZKEY_EE	0x79
#define ZKEY_RETURN	0x7a
#define ZKEY_CAL	0x82
#define ZKEY_LN	0x83
#define ZKEY_MPLUS	0x84
#define ZKEY_8	0x85
#define ZKEY_5	0x86
#define ZKEY_2	0x87
#define ZKEY_3	0x88
#define ZKEY_PLUS	0x89
#define ZKEY_MINUS	0x8a
#define ZKEY_DEGR	0x92
#define ZKEY_SIN	0x93
#define ZKEY_LPAREN	0x94
#define ZKEY_RPAREN	0x95
#define ZKEY_9	0x96
#define ZKEY_6	0x97
#define ZKEY_ASTER	0x98
#define ZKEY_SLASH	0x99
#define ZKEY_BS	0x9a
#define ZKEY_SQRT	0xa2
#define ZKEY_X2	0xa3
#define ZKEY_ENG	0xa4
#define ZKEY_CLS	0xa5
#define ZKEY_COS	0xa6
#define ZKEY_HAT	0xa7
#define ZKEY_ANS	0xa8
#define ZKEY_TAN	0xaa
#define ZKEY_DEBUG	0xfe
#define ZKEY_OFF	0xff

typedef struct {
	I86stat cpu;
	uint8 memory[0x40000 + 0x20000];

	uint8 io_b8;
	uint16 eoi;

	struct {
		uint16 count;
		uint16 interval_a;
		uint16 interval_b;
		uint16 control;
	} timer0;

	struct {
		uint16 count;
		uint16 interval_a;
		uint16 interval_b;
		uint16 control;
	} timer1;

	struct {
		uint16 count;
		uint16 interval;
		uint16 control;
	} timer2;

	struct {
		uint16 strobe;
		uint16 matrix[11];
	} key;

	struct {
		uint8 reg;
		uint8 xar;
		uint8 yar;
		uint8 fcr;
		uint8 vram[(LCD_WIDTH / 8) * LCD_HEIGHT];
	} lcd;
} Z1stat;

int init(Z1stat *, int, char **);

int initDepend(void);

void updateLCD(Z1stat *);
int updateKey(Z1stat *);
void delay(int);

#if defined(DEF_GLOBAL)
#	define EXTERN
#else
#	define EXTERN	extern
#endif

EXTERN char pathROM[PATH_MAX];
EXTERN char pathRAM[PATH_MAX];

#include "depend.h"

#endif

/* eof */
