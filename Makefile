
# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $

CC=cc -std=c11 -g -Wall -c
CXX=c++ -std=c++11 -g -Wall -o $@ 
OBJS=malib.o malib2.o socket.o
LINK=cc -o $@ $@.o -L. -lmalib
LINK2=c++ -o $@ $@.o malib2.cpp -L. -lmalib

libmalib.a: malib.c malib2.cpp malib.h socket.h socket.c
	$(CC) -D_BSD_SOURCE malib.c
	$(CC) socket.c
	$(CXX) malib2.cpp
	ar -rcs $@ $(OBJS)

.c: libmalib.a
	$(CC) $<
	$(LINK)
	rm $@.o

.cpp: malib2.cpp malib.h libmalib.a
	$(CXX) $<  malib2.cpp 
