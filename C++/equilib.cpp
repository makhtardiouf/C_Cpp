/**
 * Determine the point of equiplibrium where
 * sum (v[:i-1]) == sum(v[i+1:])
   A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1].
 * Makhtar Diouf
*/
#include "malib.hpp"
#include <cstdlib>
#include <numeric>
using namespace std;

// Watch out in case of int v[]
// Incorrect size, as an array passed as function paramenter is a pointer: int
// *v
// sizeof v / sizeof v[0];

long getEquil(vector<long> &v) {

  long sz = v.size();
  long sumA = 0, sumB = 0;
  long i = 0, j = sz - 1;
  bool inited = false;

  for (; i < j; i++) {
    sumA += v[i];

    // First run
    if (!inited) {
      inited = true;
      for (; j > i; j--) {
        sumB += v[j];
        printf("Length: %ld, Idx: %ld, %ld, Sums: %ld, %ld\n", sz, i, j, sumA,
               sumB);
      }
      if (sumA == sumB)
        return i + 1;
    }
    // backtrack
    sumB -= v[j];
    j++;
    if (sumA == sumB)
      return j - 1;
  }
  return -1;
}

int main() {
  vector<long> v = {-1, 3, -4, 5, 1, -6, 2, 1};
  long p = getEquil(v);
  printf("Equilibrium point: v[%ld] = %ld\n", p, v[p]);

  cout << "Min int: " << numeric_limits<int>::max() << endl;
  return 0;
}
