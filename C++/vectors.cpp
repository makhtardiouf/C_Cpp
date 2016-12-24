/*
 * Trivial operations on vectors
 * Author: makhtar
 * $Id$
 * Created on February 8, 2016, 8:53 PM
 * make vectors
 */
#include "malib.hpp"
using namespace std;

long long calcSum(const std::vector<std::vector<int>> &v, int x = 0,
                  int y = 0) {
  int i = 0;
  long long tot = 0;
  for (auto rows : v) {
    for (auto el : rows)
      tot += el;

    printf("\tv[%d]: %3lld\n", i, tot);
    tot = 0;
    i++;
  }
  return tot;
}

int main(int argc, char **argv) {
  clock_t t0 = clock();
  vector<int> v;
  v.assign(4, 15);

  for (int i = -3; i < 3; i++)
    v.push_back(i * 2);
  v.push_back(2);
  v.push_back(2.0); // test with double

  // Std lib sort algo with comparison function
  std::sort(v.begin(), v.end(), std::less<int>());
  printf("Sorted vector of size: %d \n", v.size());
  printV(v);

  // remove one of the '2'
  printf("\nUnique: \n");
  auto last = std::unique(v.begin(), v.end(), std::equal_to<int>());
  v.erase(last, v.end());
  printV(v);

  printf("\nReverse:\n");
  std::reverse(v.begin(), v.end());
  printV(v);
  printf("\nLast element of v: %d\n\n", v[v.size() - 1]);

  std::vector<char> txt;
  txt.assign(5, 'a');
  printV(txt);

  // 2D vector, often used in competitive programming board games
  int n = 6;
  int m = 6;
  vvi a(n); //, std::vector<int>(m));
  printf("\n2D vectors playground:\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i].push_back(i * j);
      printf("%3d ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nRow sums: \n");
  calcSum(a);

  a[3][2] = -100;
  //a[4][1] = 120;
  printf("Updated vector's a[3]: ");
  printV(a[3]);

  printf("\nMaximum sum of 1D vector v (unique elements): %d", maxSum(a[3]));

  clock_t t1 = clock();
  printf("\nRuntime = %.4f s\n", (t1 - t0) / (double)CLOCKS_PER_SEC);
  return EXIT_SUCCESS;
}
