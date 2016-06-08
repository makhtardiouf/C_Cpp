/**
STL constructs demo
*/
#include "malib.hpp"
using namespace std;

int main() {
  vector<int> v;
  for (const auto x : {1, 2, 3, 5, 8, 13, 21, 34}) {
    printf("%d ", x);
    v.push_back(x);
  }
  cout << endl;
  for (auto &x : v)
    ++x;
  printV(v);
  return 0;
}