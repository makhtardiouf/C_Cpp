# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $
# For C programs
FLAGS=-Imalib/ -Lmalib/ -lmalib -lpthread
CC=cc -std=c11 -g -Wall -fPIC $(FLAGS) -o $@ 

OBJS=malib.o malib2.o socket.o
LINK=ld -o $@ $@.o $(FLAGS) malib/libmalib.a 

all: bin 
	make malib/libmalib.a

bin :
	@mkdir -p bin        

malib/libmalib.a:
	cd malib; make; cd ..

asciiart_sleep:
	$(CC) $< asciiart_sleep.c  malib/libmalib.a -laa

.c: malib/libmalib.a bin
	if [ ! -d "bin" ]; then \
		make all; fi

	$(CC) $<  malib/libmalib.a 
	@mv $@ bin/
	@echo bin/$@ ":\t\tOK"
