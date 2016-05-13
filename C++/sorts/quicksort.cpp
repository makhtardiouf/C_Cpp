/**
   Quick sort, from the "Algo desing manual"
   Makhtar Diouf
   
   Note:  the worst case for quicksort is worse than heapsort or mergesort
Separates the n − 1 other items into two piles:
a low pile containing all the elements that appear before p in sorted order and
a high pile containing all the elements that appear after p in sorted order.

make -f ../Makefile quicksort
$Id$
*/
#include "malib.hpp"
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T> int partition(vector<T> &v, int l, int h);

template <typename T> void quicksort(vector<T> &v, int l, int h) {
  // index of partition
  int p = 0;
  printV(v);

  if ((h - l) > 0) {
    p = partition<T>(v, l, h);
    quicksort<T>(v, l, p - 1);
    quicksort<T>(v, p + 1, h);
  }
}

int main() {
  vector<int> v = {10, 5, 63, -42, 0, 9, 38, -8};
  
  auto mm = std::minmax_element(v.begin(), v.end());  
  int minIdx = mm.first - v.begin();
  int maxIdx = mm.second - v.begin();
  printf("\nMinMax: %d(%d) %d(%d)\n\n", *mm.first, minIdx, *mm.second, maxIdx);

  clockit();
  quicksort<int>(v, 0, v.size()-1);
  clockit();
  
  string s("QUICKSORT");
  vector<char> vs;
  for (auto x: s)
    vs.push_back(x); 
    
  quicksort<char>(vs, 0, vs.size()-1);
  clockit();
  return 0;
}

template <typename T> int partition(vector<T> &v, int l, int h) {
  // pivot element index
  int p = h;
  // divider position for pivot
  int firsthigh = l;

  for (int i = l; i < h; i++)
    if (v[i] < v[p]) {
      std::swap(v[i], v[firsthigh]);
      firsthigh++;
    }

  std::swap(v[p], v[firsthigh]);
  return (firsthigh);
}
