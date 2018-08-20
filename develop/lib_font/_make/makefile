CC=arm-linux-gnueabihf-gcc
AR=arm-linux-gnueabihf-ar
CFLAGS=-I.
CFLAGS+=-I../include
CFLAGS+=-I../inc

all: liblib_font.a

liblib_font.a : lib_font.o
	$(AR) rcs $@ $<

lib_font.o : ../src/lib_font.c ../src/lib_font__standard.c ../include/lib_font.h ../inc/lib_font__internal.h ../inc/lib_font__standard.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm lib_font.o
	rm liblib_font.a
