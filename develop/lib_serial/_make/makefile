CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.

lib_serial.o : ../src_linux/lib_serial_linux.c ../include/lib_serial.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: lib_serial.o

clean:
	rm lib_serial.o
