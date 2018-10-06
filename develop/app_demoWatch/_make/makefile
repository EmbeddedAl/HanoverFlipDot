CC=arm-linux-gnueabihf-gcc
MAKE=make

CFLAGS=-I.
CFLAGS+=-I../include
CFLAGS+=-I../../lib_serial/include
CFLAGS+=-I../../lib_support/include
CFLAGS+=-I../../lib_hanover/include
CFLAGS+=-I../../lib_font/include
 
LIBS=lib_support
LIBS+=lib_serial
LIBS+=lib_hanover
LIBS+=lib_font

all: app_demoWatch

lib_support :
	$(MAKE) -C ../../lib_support/_make all

lib_serial :
	$(MAKE) -C ../../lib_serial/_make all

lib_hanover :
	$(MAKE) -C ../../lib_hanover/_make all

lib_font :
	$(MAKE) -C ../../lib_font/_make all

app_demoWatch.o : ../src/app_demoWatch.c 
	$(CC) -c -o $@ $< $(CFLAGS)

app_demoWatch : $(LIBS) app_demoWatch.o
	$(CC) -L../../lib_support/_make -L../../lib_serial/_make -L../../lib_hanover/_make -L../../lib_font/_make -o $@  app_demoWatch.o -llib_font -llib_hanover -llib_serial -llib_support

clean:
	$(MAKE) -C ../../lib_support/_make clean
	$(MAKE) -C ../../lib_serial/_make clean
	$(MAKE) -C ../../lib_hanover/_make clean
	$(MAKE) -C ../../lib_font/_make clean
	rm app_demoWatch.o
	rm app_demoWatch
