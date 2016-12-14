# $Id: Makefile 18 2008-07-06 09:18:48Z Makhtar $
# For C++ folder

FLAGS=-Imalib/ -Lmalib/ -lmalib
CXX=clang++-4.0 -std=c++14 -g -Wall -fPIC $(FLAGS) -o $@

OBJS=malib.o malib2.o socket.o
MLIB=malib/libmalib.a
LINK=ld -o $@ $@.o $(FLAGS) $(MLIB)
#LINKPP=c++ -o $@ $@.o $(FLAGS)

all: bin
	make $(MLIB)
	@cd ..

bin :
	@mkdir -p bin

$(MLIB):
	cd malib; make; cd ..
# if [ ! -d "malib" ] then cd .. fi

strings:
	$(CXX) $< strings.cpp  $(MLIB) -lasprintf

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

.cpp: $(MLIB)
	if [ ! -d "bin" ]; then \
		make all; fi

	$(CXX) $<  $(MLIB)
	@mv $@ bin/
	@echo bin/$@ ":\t\tOK"
