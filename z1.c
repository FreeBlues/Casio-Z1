#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define DEF_GLOBAL
#include "z1.h"

#ifndef O_BINARY
#define O_BINARY	0
#endif

void i86trace(const I86stat *i86)
{
	char buf[256];

	printf("%s%dclocks\n\n", i86regs(buf, i86), i86->i.total_states - i86->i.states);
	fflush(stdout);
}

static int readROM(const char *path, uint8 *p)
{
	FILE *fp;
	int i, x;
	char buf[256];

	if((fp = fopen(path, "r")) == NULL) {
		/*
		strcpy(buf, getexedir());
		strcat(buf, "\\");
		strcat(buf, path);
		if((fp = fopen(buf, "r")) == NULL)
			return FALSE;
		*/
		return FALSE;
	}

	while(!feof(fp)) {
		fgets(buf, sizeof(buf), fp);
		for(i = 0; i < strlen(buf); i += 2)
			if(isalnum(buf[i])) {
				sscanf(&buf[i], "%02x", &x);
				*p++ = (uint8 )x;
			}
	}

	fclose(fp);
	return TRUE;
}

static int readBin(const char *path, void *p)
{
	int fd, size;

	if((fd = open(path, O_RDONLY | O_BINARY)) < 0) {
		fprintf(stderr, "CANNOT OPEN %s\n", path);
		return 0;
	}
	size = read(fd, p, 0x20000);
	close(fd);

	if(memcmp(p, "\xff\xfe", 2) == 0) {
		memmove(p, ((uint8 *)p) + 16, size - 16);
		size -= 16;
	}
	return size;
}

static int writeBin(const char *path, uint8 *p, int size)
{
	int fd;
	int written;

	if((fd = open(path, O_CREAT | O_TRUNC | O_WRONLY | O_BINARY, 0664)) < 0)
		return 0;
	written = write(fd, p, size);
	close(fd);

	return written;
}

static int atoix(const char *buf)
{
	int x;

	sscanf(buf, "%x", &x);
	return x;
}

int main(int argc, char *argv[])
{
	Z1stat z1;
	int test = 0;
	int freq = 240;
	int intr;
	int i;

	init(&z1, argc, argv);
	if(!initDepend())
		return 1;

	z1.cpu.i.tag = &z1;
	z1.cpu.m = z1.memory;
	z1.cpu.i.trace = 0;

	memset(z1.memory, 0, sizeof(z1.memory));
	if(!readROM(pathROM, z1.memory + 0x40000)) {
		fprintf(stderr, "CANNOT OPEN ROM IMAGE. (%s)\n", pathROM);
		return 1;
	}
	if(readBin(pathRAM, z1.memory) <= 0)
		for(i = 0; i < 0x2000; i++)
			z1.memory[i] = i & 0xff;
	if(argc > 1) {
		if((test = readBin(argv[1], z1.memory + 0x2000)) == 0) {
			fprintf(stderr, "CANNOT OPEN %s\n", argv[1]);
			return 1;
		}
	}

	i86reset(&z1.cpu);
	z1.eoi = 0x8000;
	z1.cpu.i.states = 0;

	for(;;) {
		do {
			z1.cpu.i.states += 2000 * 1024 / freq;
			delay(1000 / freq);
		} while(z1.cpu.i.states < 0);
		if(i86exec(&z1.cpu) == I86_HALT) {
			if(z1.io_b8 == 1 && !(z1.cpu.r16.f & 0x0200))
				break;
			if(test != 0) {
				test = 0;
				z1.cpu.r16.cs = 0;
				if(argc > 2)
					z1.cpu.r16.ip = atoix(argv[2]);
				else
					z1.cpu.r16.ip = 0x2000;
				z1.cpu.r16.hlt = 0;
			}
		}

		updateLCD(&z1);
		switch((intr = updateKey(&z1))) {
		case 0x03:
			i86nmi(&z1.cpu);
			break;
		case 0x0c:
			if(z1.eoi & 0x8000)
				if(i86int(&z1.cpu, intr))
					z1.eoi = 0;
			break;
		}
		/*
		if((z1.timer0.control & 0xe001) == 0xe001) {
			if(z1.eoi & 0x8000)
				if(i86int(&z1.cpu, 0x08))
					z1.eoi = 0;
		}
		if((z1.timer1.control & 0xe001) == 0xe001) {
			if(z1.eoi & 0x8000)
				if(i86int(&z1.cpu, 0x12))
					z1.eoi = 0;
		}
		*/
		if((z1.timer2.control & 0xe001) == 0xe001) {
			if(z1.eoi & 0x8000)
				if(i86int(&z1.cpu, 0x13))
					z1.eoi = 0;
			/*
			if((int )z1.timer2.count + 15360 / (freq / 60) >= (int )z1.timer2.interval) {
				i86int(&z1.cpu, 0x13);
				z1.timer2.count = 0;
			} else
				z1.timer2.count += 15360 / (freq / 60);
			*/
		}
	}

	if(strcmp(pathRAM, "") != 0)
		writeBin(pathRAM, z1.memory, 0x40000);

	return 0;
}

/* eof */
