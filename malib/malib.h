/* $Id: malib.h,v 71f8a7269804 1434171018.0-32400 makhtar $
*   Collection of C routines for libmalib
*  (C) Makhtar Diouf 2007-2016
*/
#ifndef MALIB_H
#define MALIB_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __unix__
#include <error.h>
#include <sys/wait.h>
#endif

#ifdef __cplusplus
/*
* Protect C functions from being mangled
* by the linker when called from a C++ program
*/
extern "C" {
#endif

/** Number of elements of an array */
#define getArrLength(array) (sizeof(array) / sizeof(array[0]))

/** Time program execution */
double clockit();

void terminate(const char *s);

/** Clear the console */
int clearconsole(void);

/** Catch signals and do appropriate cleanup when necessary */
void handle_signal(int signum);

/** Pause program execution */
void pausethis(int sec);

/** Print the binary representation of a number */
void printBinary(const unsigned char val);

/** Reverse a string */
char *reverse(char s[]);

/** Print animated dash  */
void rotate_dash(void);

/** Presents a console menu to the user */
int show_menu(char *menu[]);

/** Print a string in unbuffered mode,  */
void typewrite(const char *name);

/** Avoid the abrupt closing of the console on MS-WINDOWS  */
void w32_wait(void);

char *remove_duplicates(char str[]);

#ifdef __cplusplus
}
#endif

#endif // MALIB.H
