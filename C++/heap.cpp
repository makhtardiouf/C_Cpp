/**
 Map Heap

Complexity: at most 3 * distance(first, last) comparisons.

http://en.cppreference.com/w/cpp/algorithm/make_heap
*/
#include "malib.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{3, 1, 4, 1, 5, 9};
  cout << "Input: ";
  printV(v);

  make_heap(v.begin(), v.end());
  cout << v[0] << endl;

  cout << "\nafter make_heap, v: ";
  printV(v);

  pop_heap(v.begin(), v.end());
  auto largest = v.back();
  v.pop_back();
  cout << "\nlargest element: " << largest << '\n';

  cout << "\nafter removing the largest element, v: ";
  printV(v);
}
