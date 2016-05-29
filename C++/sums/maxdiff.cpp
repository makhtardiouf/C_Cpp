
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/**
Return maximum difference between 2 elements at pos i, j
with j > i, v[j] > v[i]
Better use a tree or other Compet prog techniques for a large number of elements
*/
int maxDifference(vector<int> &v) {
 // auto result = std::minmax_element(v.begin(), v.end());
  auto itMax = std::max_element(v.begin(), v.end());
  auto itMin = std::min_element(v.begin(), itMax);

  int maxDiff = -1;
  printf("MinMax: %d %d\n", *itMin, *itMax);

  if (itMax > itMin)
    return *itMax - *itMin;
  else
    while (v.size() > 0 && (itMax <= itMin)) {
      v.erase(itMax);
      if (itMax == itMin)
        itMin = std::min_element(v.begin(), itMax);
        
      itMax = std::max_element(itMin-1, v.end());
      maxDiff = std::max(maxDiff, *itMax - *itMin);
    }

  return maxDiff;
}

int main() {
  // char mess[]  = "Hello World";
  vector<int> v = {70, 20, 9, 10, 5, -6};
  printf("MaxDiff of vect: %d\n", maxDifference(v));
  return 0;
}