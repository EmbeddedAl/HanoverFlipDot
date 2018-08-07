CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.

lib_hanover.o : ../src/lib_hanover.c ../include/lib_hanover.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: lib_hanover.o

clean:
	rm lib_hanover.o
