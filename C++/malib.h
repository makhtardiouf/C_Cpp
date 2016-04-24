/* $Id: malib.h,v 71f8a7269804 1434171018.0-32400 makhtar $
   Collection of utilities
   Note: to be included before standard library headers
   Makhtar Diouf 2007-2016
*/
#ifndef MALIB_H
#define MALIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef __unix__
# include <sys/wait.h>
# include <error.h>
#endif

#ifdef __cplusplus
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

// template<typename T>
std::ostream& operator<<(std::ostream& ostr, const std::list<std::string>& list);

// Competitive programming utilities
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;

// UFDS: Union-Find Disjoint Sets
std::vector<int> pset(100);
inline void initSet(int _size)
{
    pset.resize(_size);
    for (int i=0; i < _size; i++) pset[i] = i;
}
inline int findSet(int i)
{
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
inline void unionSet(int i, int j)
{
    pset[findSet(i)] = findSet(j);
}
inline bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

// Run subprocess
int spawn(const char* cmd[] );


// Print a vector's content of any type, with -std=c++14
#if __cplusplus > 201103L
  void printV(std::vector<auto> v)
{
    for(auto x : v)
      std::cout << "\t" << x << " ";
    std::cout << std::endl;
}
#endif

/*
 * Functions written in C must be protected from being mangled
 * by the linker when called from a C++ program
 */
extern "C"
{
#endif

    /** Number of elements of an array */
#define getArrLength(array) (sizeof(array) / sizeof(array[0]))

    void terminate(const char* s);

    /** Clear the console */
    int clearconsole(void);

    /** Catch signals and do appropriate cleanup when necessary */
    void handle_signal(int signum);

    /** Pause program execution */
    void pausethis(int sec);

    /** Print the binary representation of a number */
    void printBinary(const unsigned char val);

    /** Produce a reversed string */
    char* reverse(char s[]);

    /** Output an animated dash  */
    void rotate_dash(void);

    /** Presents a console menu to the user */
    int show_menu(char* menu[] );

    /** Print a string in unbuffered mode,  */
    void typewrite(const char* name);

    /** Avoid the abrupt closing of the console on MS-WINDOWS  */
    void w32_wait(void);

    char* remove_duplicates(char str[]);

#ifdef __cplusplus
}
#endif

#endif
