# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $

#CC=gcc -std=c11 -g -Wall -c
CXX=g++ -std=c++11 -g -Wall -c
OBJS=malib.o malib2.o socket.o
#LINK=gcc -o $@ $@.o -L. -lmalib
LINK2=g++ -g -Wall -o $@ $@.cpp -L. -lmalib

.cpp: malib.c malib2.cpp malib.h
	$(LINK2)
	rm $@.o

# char_code: char_code.c libmalib.a
# 	$(CC) $<
# 	$(LINK) -lreadline
