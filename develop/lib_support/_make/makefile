CC=arm-linux-gnueabihf-gcc
AR=arm-linux-gnueabihf-ar
CFLAGS=-I.
CFLAGS+=-I../include

all: liblib_support.a

liblib_support.a : lib_support.o lib_support_linux.o
	$(AR) rcs $@ lib_support.o lib_support_linux.o

lib_support_linux.o: ../src_linux/lib_support_linux.c ../include/lib_support.h
	$(CC) -c -o $@ $< $(CFLAGS)

lib_support.o : ../src/lib_support.c ../include/lib_support.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm lib_support.o
	rm lib_support_linux.o
	rm liblib_support.a
