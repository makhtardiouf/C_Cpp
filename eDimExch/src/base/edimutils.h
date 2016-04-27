/*****************************************************************
 * $Id: edimutils.h, ca5aafa57b53  makhtar $
 * Copyright (C) 2006-2007 Makhtar Diouf
 * elmakdi@users.sourceforge.net
 *
 * -You can redistribute and/or modify this program
 *  under the terms of the GNU General Public License version 2.
 *  See the file COPYING for further information.
 *
 * -Vous pouvez redistribuer et/ou modifier ce programme
 *  sous les termes de la license GNU General Public version 2.
 *  Voir le fichier COPYING pour plus d'information.
 ****************************************************************/

/* Collection of  utility functions and variables  */
#ifndef PROJUTILS_H
#define PROJUTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef __unix__
# include <sys/wait.h>
/*# include <error.h> */
#endif

/* REMEMBER: Functions written in C must be
protected from being mangled by the linker
when called from a C++ program */
#ifdef __cplusplus
extern "C"
{
#endif

    /** Disable console auto-closing on Windows */
    extern void w32_wait(void);

    extern void pausethis(int microsec);

    extern int show_menu(char* menu[] );

    extern int clearconsole(void);

    /** Print a string in unbuffered mode */
    extern void slowcout(const char* name);

    extern void handle_signal(int signum);

    /** Produce a reversed string */
    extern char* reverse(char s[]);

#ifdef __cplusplus
}
#endif

/* Get the execee's name and arguments then fork it */
extern int spawn(const char* cmd[]);
#endif
