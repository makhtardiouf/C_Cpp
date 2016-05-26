/*
 * Trivial operations on vector
 * Author: makhtar
 * $Id$
 * Created on February 8, 2016, 8:53 PM
 * make vectors
 */
#include "malib.hpp"
using namespace std;

long long calcSum(const std::vector<std::vector<int>> &a, int x = 0,
                  int y = 0) {
  long long value = 0;
  int n = a.size();
  int m = a[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      value += a[i][j];
    }
    cout << "\ta[" << i << "]:" << value << endl;
    value = 0;
  }
  return value;
}

int main(int argc, char **argv) {
  clock_t t0 = clock();
  vector<int> v;
  v.assign(4, 15);

  for (uint8_t i = 0; i < 5; i++)
    v.push_back(i);
  v.push_back(2);
  v.push_back(2.0);     // test with double

  // Std lib sort algo with comparison function
  std::sort(v.begin(), v.end(), std::less<int>());
  cout << "Sort vector of size: " << v.size() << " \n";
  printV(v);

  // remove one of the '2'
  cout << "\nUnique: \n";
  auto last = std::unique(v.begin(), v.end(), std::equal_to<int>());
  v.erase(last, v.end());
  printV(v);

  cout << "\nReverse:\n";
  std::reverse(v.begin(), v.end());
  printV(v);
  cout << "\nLast element of v: " << v[v.size() - 1] << "\n";

  std::vector<char> txt;
  txt.assign(5, 'a');
  printV(txt);

  // 2D vector, often used in competitive programming board games
  int n = 6;
  int m = 6;
  vvi a(n); //, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      //a[i][j] = i * j;
      a[i].push_back(i * j);
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Row sums of 2D vect: \n";
  calcSum(a);

  a[3][2] = 100;
  printV(a[3]);

  cout << "Maximum sum of the vect a's subsets: " << maxSum(a) << endl;

  clock_t t1 = clock();
  printf("\nRuntime = %.4f s\n", (t1 - t0) / (double)CLOCKS_PER_SEC);

  return EXIT_SUCCESS;
}
