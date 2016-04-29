/*
 * $Id$
 * maximum value of (Sum of Subarray ) %M
 * Author: makhtar
 * This version is slow on large N
 * c++ -g -std=c++11 maxsum.cpp -o maxsum -DDEBUG=1  -I../malib/ -L../malib -lmalib
 * Ref: https://www.hackerrank.com/challenges/maximise-sum
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#ifdef DEBUG
#include "malib.hpp"
#endif
using namespace std;

// Not the Kardane algo, because of the modulo
ull maxSum(std::vector<ull> &A, ull M) {
  const ull n = A.size();
  ull sum = 0, ans = 0;
  set<ull> S;
  S.insert(0);
  set<ull>::iterator it;

  for (ull i = 0; i < n; i++) {
    sum += A[i];
    sum %= M;
    it = S.upper_bound(sum);
    if (it != S.end())
      ans = max({ans, sum, sum - (*it) + M});
    else
      ans = max(ans, sum);
    //  fprintf(stderr, "i:%llu %llu\n", i, ans);
    S.insert(sum);
  }
  return ans;
}

int main() {
  clock_t t0 = clock();
  int nCases;
  cin >> nCases;

  for (int k = 0; k < nCases; k++) {
    ull N, M = 0;
    cin >> N >> M;
    std::vector<ull> A(N);
    for (ull i = 0; i < N; i++) {
      cin >> A[i];
    }
    printf("%llu\n", maxSum(A, M));
    //clog << "Case " << k + 1 << ": " << maxSum(A, M) << endl;
  }

  clock_t t1 = clock();
  fprintf(stderr, "\nRuntime = %.4f s\n", (t1 - t0) / (double)CLOCKS_PER_SEC);
  return 0;
}
