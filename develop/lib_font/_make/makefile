CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.
CFLAGS+=-I../include
CFLAGS+=-I../inc

lib_font.o : ../src/lib_font.c ../src/lib_font__standard.c ../include/lib_font.h ../inc/lib_font__internal.h ../inc/lib_font__standard.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: lib_font.o

clean:
	rm lib_font.o
