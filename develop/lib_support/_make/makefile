CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.
CFLAGS+=-I../include

lib_support.o : ../src/lib_support.c ../src_linux/lib_support_linux.c ../include/lib_support.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: lib_support.o

clean:
	rm lib_support.o
