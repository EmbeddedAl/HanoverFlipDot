CC=arm-linux-gnueabihf-gcc
AR=arm-linux-gnueabihf-ar
CFLAGS=-I.
CFLAGS+=-I../include
CFLAGS+=-I../../lib_serial/include
CFLAGS+=-I../../lib_support/include

all: lib_hanover.a

lib_hanover.a : lib_hanover.o
	$(AR) rcs $@ $<

lib_hanover.o : ../src/lib_hanover.c ../include/lib_hanover.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm lib_hanover.o
	rm lib_hanover.a
