# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $

CC=gcc -std=c11 -g -Wall -c
CXX=g++ -std=c++11 -g -Wall -c
OBJS=malib.o malib2.o socket.o
LINK=gcc -o $@ $@.o -L. -lmalib
LINK2=g++ -o $@ $@.o -L. -lmalib

libmalib.a: malib.c malib2.cpp malib.h socket.h socket.c
	$(CC) -D_BSD_SOURCE malib.c
	$(CC) socket.c
	$(CXX) malib2.cpp
	ar -rcs $@ $(OBJS)

.c: libmalib.a
	$(CC) $<
	$(LINK)
	rm $@.o

.cpp: libmalib.a malib.h
	$(CXX) $<
	$(LINK2)
	rm $@.o

# char_code: char_code.c libmalib.a
# 	$(CC) $<
# 	$(LINK) -lreadline
