
# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $

CC=cc -std=c11 -g -Wall -c
CXX=c++ -std=c++11 -g -Wall -I../malib -L../malib/ -lmalib -o $@ 
OBJS=malib.o malib2.o socket.o
LINK=cc -o $@ $@.o -I../malib -L../malib -lmalib
LINKPP=c++ -o $@ $@.o -L. -lmalib

all:
	#if [ -d "build" ] then
	@mkdir -p build
	#fi
	make -s malib/libmalib.a

malib/libmalib.a:
	cd malib; make; cd ..

fltkpipe:
	$(CXX) $< `fltk-config --cxxflags` fltkpipe.cpp -std=c++11  -lfltk -lXext -lX11 -lm

.cpp: malib/libmalib.a
	@make -s all	
	$(CXX) $< 
	@mv $@ build/
	@echo build/$@ ":\t\tOK"

.c: malib/libmalib.a
	$(CC) $<
	$(LINK)
	rm $@.o
	