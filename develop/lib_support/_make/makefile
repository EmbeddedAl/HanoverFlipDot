CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.

lib_support.o : ../src/lib_support.c ../include/lib_support.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: lib_support.o

clean:
	rm lib_support.o
