CC=arm-linux-gnueabihf-gcc
MAKE=make

CFLAGS=-I.
CFLAGS+=-I../include
CFLAGS+=-I../../lib_serial/include
CFLAGS+=-I../../lib_support/include
CFLAGS+=-I../../lib_hanover/include
 
LIBS=lib_support
LIBS+=lib_serial
LIBS+=lib_hanover

all: app_demoReplayText

lib_support :
	$(MAKE) -C ../../lib_support/_make all

lib_serial :
	$(MAKE) -C ../../lib_serial/_make all

lib_hanover :
	$(MAKE) -C ../../lib_hanover/_make all

app_demoReplayText.o : ../src/app_demoReplayText.c 
	$(CC) -c -o $@ $< $(CFLAGS)

app_demoReplayText : $(LIBS) app_demoReplayText.o
	$(CC) -L../../lib_support/_make -L../../lib_serial/_make -L../../lib_hanover/_make -o $@  app_demoReplayText.o -llib_hanover -llib_serial -llib_support

clean:
	$(MAKE) -C ../../lib_support/_make clean
	$(MAKE) -C ../../lib_serial/_make clean
	$(MAKE) -C ../../lib_hanover/_make clean
	rm app_demoReplayText.o
	rm app_demoReplayText
