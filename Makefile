# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $
# For C++ folder

FLAGS=-Imalib/ -Lmalib/ -lmalib
CXX=clang++-4.0 -std=c++11 -g -Wall -fPIC $(FLAGS) -o $@

OBJS=malib.o malib2.o socket.o
LINK=ld -o $@ $@.o $(FLAGS) malib/libmalib.a
#LINKPP=c++ -o $@ $@.o $(FLAGS)

all: bin
	make malib/libmalib.a

bin :
	@mkdir -p bin

malib/libmalib.a:
	cd malib; make; cd ..
# if [ ! -d "malib" ] then cd .. fi

strings:
	$(CXX) $< strings.cpp  malib/libmalib.a -lasprintf

divisors:
	$(CXX) $< divisors.cpp -I/usr/local/include/fxt -lfxt
	mv $@ bin/

fltkpipe:
	$(CXX) $< `fltk-config --cxxflags` fltkpipe.cpp -lfltk -lXext -lX11 -lm

hellofltk:
	$(CXX) $< `fltk-config --cxxflags` hellofltk.cpp -lfltk -lXext -lX11 -lm

lists:
	echo # pass

elevator:
	$(CXX) $< elevator.cpp -lpthread
	@mv $@ bin/

.cpp: malib/libmalib.a
	if [ ! -d "bin" ]; then \
		make all; fi

	$(CXX) $<  malib/libmalib.a
	@mv $@ bin/
	@echo bin/$@ ":\t\tOK"
