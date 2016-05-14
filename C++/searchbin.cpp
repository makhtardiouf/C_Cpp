/**
   Binary search using std::lower_bound / upper_bound

   Makhtar diouf
   $Id$
   c++ -std=c++11 -g -Wall -o searchbin searchbin.cpp -Lmalib/ -lmalib
*/
#include "malib.hpp"
using namespace std;

template <typename T> 
long binSearch(vector<T> s, T key, int low, int high) {
    
  int mid = 0; // idx
  
  // key not found
  if (low > high)
    return (-1);
    
    mid = (low + high) / 2;

  if (s[mid] == key)
    return (mid);
    
  if (s[mid] > key)
    return (binSearch(s, key, low, mid - 1));
  else
    return (binSearch(s, key, mid + 1, high));
}

int main() {
  clockit();
  std::vector<long> v;
  for (int i = 0; i < 1e5; i++) {
    v.push_back(i * 2);
  }

  printf("Vector of size: %lu\n", v.size());
  printV(v);

  auto it = std::lower_bound(v.begin(), v.end(), 40);
  printf("\nTarget lower_bound (geq): %ld, Idx: %ld\n", *it, it - v.begin());

  it = std::upper_bound(v.begin(), v.end(), 180);
  printf("Target upper_bound 180: %ld, Idx: %ld\n", *it, it - v.begin());
  clockit();
  
  auto val = binSearch<long>(v, 180, 0, v.size() - 1);
  printf("Custom binSearch 180: Idx: %ld\n", val);
  clockit();
  return 0;
}
