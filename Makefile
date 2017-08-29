EXE = z1
CC = gcc
OBJS = z1.o init.o conf.o i80x86.o i80x86asm.o memory.o io.o depend.o
CFLAGS = -DI86_USE_SDL -O3 -Wall $(shell sdl-config --cflags)
LDFLAGS = -s $(shell sdl-config --libs)

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
.c.o:
	$(CC) -c $(CFLAGS) $<
i80x86.o: i80x86.c i80x86.h
i80x86asm.o: i80x86asm.c i80x86.h
z1.o: z1.c z1.h
src:
	rm -r -f z1
	mkdir z1
	cp -p Makefile *.c *.h z1/
	nkf -w80 -Lu < readme.txt > z1/readme.txt
	nkf -w80 -Lu < z1config.linux > z1/z1config
	tar -c z1/ | gzip -9 > z1.tgz
	rm -r -f z1
win32:
	rm -r -f z1_win32
	mkdir z1_win32
	cp -p z1.exe README-SDL.txt SDL.dll z1_win32/
	nkf -s -Lw < readme.txt > z1_win32/readme.txt
	nkf -s -Lw < z1config.win32 > z1_win32/z1config
	zip -u -9 z1_win32.zip z1_win32/*
	rm -r -f z1_win32
mac:
	rm -r -f z1_mac
	mkdir z1_mac
	cp -p z1 z1_mac/
	nkf -s -Lm < readme.txt > z1_mac/readme.txt
	nkf -s -Lm < z1config.mac > z1_mac/z1config
	zip -u -9 z1_mac.zip z1_mac/*
	rm -r -f z1_mac
clean:
	rm -f *.o
	rm -f $(EXE)
	rm -f $(EXE).exe
	rm -f *.zip
	rm -f *.tgz
	rm -f stdout.txt
	rm -f stderr.txt
