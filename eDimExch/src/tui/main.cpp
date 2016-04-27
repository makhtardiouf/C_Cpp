
/* $Id: main.cpp 2 2007-02-05 09:17:01Z elmakdi $

Original Copyright (c) 1998-2002,2003 Free Software Foundation, Inc.
Originally written by Juergen Pfeifer, 1997  */

#include "Tui.hpp"

#if HAVE_LOCALE_H
#include <locale.h>
#else
#define setlocale(name,string) /* nothing */
#endif

/* This is the default implementation of main() for a NCursesApplication.
 * You only have to instantiate a static NCursesApplication object in your
 * main application source file and link this module with your application.
 */

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");

  NCursesApplication* A = NCursesApplication::getApplication();

  if (!A)
    return(EXIT_FAILURE);

  else 
    {
    int res;

    A->handleArgs(argc,argv);
    ::endwin();
    res = (*A)();
    ::endwin();
    return(res);
  }
}
