CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.
CFLAGS+=-I../include
CFLAGS+=-I../../lib_serial/include
CFLAGS+=-I../../lib_support/include

lib_hanover.o : ../src/lib_hanover.c ../include/lib_hanover.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: lib_hanover.o

clean:
	rm lib_hanover.o
