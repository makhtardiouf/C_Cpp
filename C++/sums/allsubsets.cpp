/**
 * Print all subsets with sum equal to n
 * Makhtar Diouf
*/
#include "malib.hpp"
#include <cstring>
using namespace std;

vector<int> v;

void printSubsets(int n, string x) {
  char tmp[10];
  if (n == 0) {
      // Can either print the string here, or the content of v,
      // after all processing is done
    cout << x;
    return;

  } else {
    for (int i = 1; i <= n; i++) {
      v.push_back(i);

      sprintf(tmp, "%2s%d", x.c_str(), i);
      x = string(tmp);
      printSubsets(n - i, x);
      x = x.substr(0, x.size() - 1);
    }
    // Mark new set
    v.push_back(-1);
    printf("\n");
  }
}

int main() {
  printSubsets(4, "");

cout << "\nVector style:\n";
  for (auto i : v) {
    if (i == -1)
      cout << endl;
    else
      cout << i << " ";
  }
  return 0;
}
