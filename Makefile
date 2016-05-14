# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $
FLAGS=-Imalib/ -Lmalib/ -lmalib
CC=cc -std=c11 -g -Wall -c -fPIC $(FLAGS) 
CXX=c++ -std=c++11 -g -Wall -fPIC $(FLAGS) -o $@ 

OBJS=malib.o malib2.o socket.o
LINK=ld -o $@ $@.o $(FLAGS) malib/libmalib.a 
#LINKPP=c++ -o $@ $@.o $(FLAGS)

all: build 
	make malib/libmalib.a

build :
	@mkdir -p build        
		
malib/libmalib.a:
	#if [ ! -d "malib" ] then cd .. fi
	cd malib; make; cd ..

divisors:
	$(CXX) $< divisors.cpp -I/usr/local/include/fxt -lfxt
	mv $@ build/
	
fltkpipe:
	$(CXX) $< `fltk-config --cxxflags` fltkpipe.cpp -lfltk -lXext -lX11 -lm

hellofltk:
	$(CXX) $< `fltk-config --cxxflags` hellofltk.cpp -lfltk -lXext -lX11 -lm

lists:
	echo # pass
	
.cpp: malib/libmalib.so build 
	@make -s all	
	$(CXX) $<  malib/libmalib.a 
	@mv $@ build/
	@echo build/$@ ":\t\tOK"

.c: malib/libmalib.a build 
	$(CC) $<
	$(LINK)
	rm $@.o
	