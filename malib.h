/* $Id: malib.h,v 71f8a7269804 1434171018.0-32400 makhtar $

Collection of utility functions and variables
Note: When including this file, put it before standard library headers 
*/

#ifndef MALIB_H
#define MALIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef __unix__
# include <sys/wait.h>
/*# include <error.h> */
#endif

#ifdef __cplusplus
#include <iostream>
#include <list>
#include <string>

//template<typename T>
extern std::ostream& operator<<(std::ostream& ostr, const std::list<std::string>& list);

/* 
 * Functions written in C must be protected from being mangled 
 * by the linker when called from a C++ program 
 */
extern "C"
{
#endif

  /** Return the number of elements of an array */
#define LENGTH(array) (sizeof(array) / sizeof(array[0])

    extern void terminate(const char* s);

  /** Clear the console */
    extern int clearconsole(void);

    /** Catch signals and do appropriate cleanup when necessary */
    extern void handle_signal(int signum);

  /** Pause program execution */
    extern void pausethis(int sec);

  /** Print the binary representation of a number */
    extern void printBinary(const unsigned char val);

  /** Produce a reversed string */
    extern char* reverse(char s[]);

  /** Output an animated dash  */
    extern void rotate_dash(void);

  /** Presents a console menu to the user */
    extern int show_menu(char* menu[] );

    /** Print a string in unbuffered mode,  */
    extern void typewrite(const char* name);

    /** Avoid the automatic closing of the console on MS-WINDOWS  */
    extern void w32_wait(void);

    extern char* remove_duplicates(char str[]);
    
#ifdef __cplusplus
}
#endif

//extern int spawn(const char* cmd[]);

#endif
