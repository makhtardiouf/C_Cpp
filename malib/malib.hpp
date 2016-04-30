#ifndef MALIB_HPP
#define MALIB_HPP

#include "malib.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// C++ routines for libmalib, Mahtar Diouf

template <typename T>
std::ostream &operator<<(std::ostream &ostr, const std::list<T> &list);

// Constructs used in competitive programming
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector< std::vector<int> > vvi;
typedef unsigned long long ull;

// Maximum sum of subsets of an array/vectors

extern ull rangeMaxSum(std::vector<ull> &a, ull M);

int maxSum(vvi &v);

enum Range { SUM = 0, MIN, MAX };

// Run subprocess
int spawn(const char *cmd[]);

// Print a vector's content of any type, with -std=c++11
template <typename T> void printV(std::vector<T> v) {
  for (T x : v)
    std::cout << "\t" << x << " ";
  std::cout << "\n";
}


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

#endif
