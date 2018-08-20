CC=arm-linux-gnueabihf-gcc
AR=arm-linux-gnueabihf-ar
CFLAGS=-I.
CFLAGS+=-I../include

all: lib_support.a

lib_support.a : lib_support.o
	$(AR) rcs $@ $<

lib_support.o : ../src/lib_support.c ../src_linux/lib_support_linux.c ../include/lib_support.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm lib_support.o
	rm lib_support.a
