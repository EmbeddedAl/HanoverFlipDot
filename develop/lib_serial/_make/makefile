CC=arm-linux-gnueabihf-gcc
AR=arm-linux-gnueabihf-ar
CFLAGS=-I. 
CFLAGS+=-I../include

all: liblib_serial.a

liblib_serial.a : lib_serial.o
	$(AR) rcs $@ $<

lib_serial.o : ../src_linux/lib_serial_linux.c ../include/lib_serial.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm lib_serial.o
	rm liblib_serial.a
