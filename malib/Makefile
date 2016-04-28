
# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $

CC=cc -std=c11 -g -Wall -c -Imalib
CXX=c++ -std=c++11 -g -Wall -Imalib #-o $@ 
OBJS=malib.o malib2.o 
LINK=cc -o $@ $@.o -Lmalib -lmalib
LINK2=c++ -o $@ $@.o malib2.cpp -Lmalib -lmalib

libmalib.a: malib.c malib.h malib2.cpp malib.hpp #socket.h socket.c
	$(CC) -D_BSD_SOURCE malib.c 
	#$(CC) socket.c
	$(CXX) -c malib2.cpp
	ar -rcs $@ $(OBJS)

.c: libmalib.a
	$(CC) $<
	$(LINK)
	rm $@.o

.cpp: malib2.cpp malib.c malib.hpp
	$(CXX) $<  malib2.cpp
