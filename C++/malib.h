/* $Id: malib.h,v 71f8a7269804 1434171018.0-32400 makhtar $
*   Collection of utilities
*   Note: include it before standard library headers
*   Makhtar Diouf 2007-2016
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
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

/*
* Functions written in C must be protected from being mangled
* by the linker when called from a C++ program
*/
extern "C" {
#endif

/** Number of elements of an array */
#define getArrLength(array) (sizeof(array) / sizeof(array[0]))

void terminate(const char *s);

/** Clear the console */
int clearconsole(void);

/** Catch signals and do appropriate cleanup when necessary */
void handle_signal(int signum);

/** Pause program execution */
void pausethis(int sec);

/** Print the binary representation of a number */
void printBinary(const unsigned char val);

/** Produce a reversed string */
char *reverse(char s[]);

/** Output an animated dash  */
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


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const std::list<T> &list);

// Constructs used in competitive programming
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector< std::vector<int> > vvi;
typedef unsigned long long ull;

extern ull rangeMaxSum(std::vector<ull> &a, ull M);
// Maximum sum of subsets of an array/vector
int maxSum(vvi &v);
enum Range { SUM = 0, MIN, MAX };

// UFDS: Union-Find Disjoint Sets
class Ufds {
private:
  std::vector<int> pset;

public:
  Ufds(int sz) { pset.resize(sz); }

  inline void initSet(int _size) {
    pset.resize(_size);
    for (int i = 0; i < _size; i++)
      pset[i] = i;
  }

  inline int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
  }

  inline void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }

  inline bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
};

// Run subprocess
int spawn(const char *cmd[]);

// Print a vector's content of any type, with -std=c++11
// #if __cplusplus > 201103L
template <typename T> void printV(std::vector<T> v) {
  for (T x : v)
    std::cout << "\t" << x << " ";
  std::cout << "\n";
}

#endif // MALIB.H
