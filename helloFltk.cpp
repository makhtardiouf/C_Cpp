/*
$Id
*/

#include "fltk.hpp"
#include <cstdio>


int main(int argc, char **argv)
{

// 	Fl_Window *window = new Fl_Window(300, 180);
// 	Fl_Box *box = new Fl_Box(20, 40, 260, 100, "Hello, World!");
// 	box->box(FL_UP_BOX);
// 	box->labelsize(36);
// 	box->labelfont(FL_BOLD + FL_ITALIC);
// 	box->labeltype(FL_SHADOW_LABEL);
// 	window->end();
// 	window->show(argc, argv);
// 	fprintf(stderr, "Fl version is: %g\n", FL_VERSION);
// 	return Fl::run();

    Window *window = new Window(300, 400);
    FrameBox *box = new FrameBox(20, 40, 260, 50, "Hello, World!");
    box->box(UP_BOX);
    box->labelsize(36);
    box->labelfont(FL_BOLD + FL_ITALIC);
    box->labeltype(FL_SHADOW_LABEL);

    window->end();
    window->show(argc, argv);

    fprintf(stderr, "Fl version is: %g\n", FL_VERSION);
    fprintf(stderr, "Fl major version is: %d\n", FL_MAJOR_VERSION);

    return run();

}

/*
compile, link with

g++ -o fltk_hello fltk_hello.cpp -I/usr/X11R6/include -O2 -march=i586\
 -mcpu=i686 -fmessage-length=0 -Wall -I/usr/X11R6/include\
 -L/usr/X11R6/lib -Wl,-rpath,/usr/X11R6/lib\
 -lfltk -lm -lXext -lX11 -lsupc++
*/

