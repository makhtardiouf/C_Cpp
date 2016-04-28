/*
 * $Id$
 * maximum value of (Sum of Subarray ) %M
 * Author: makhtar
 * This version is slow on large N
 * c++ -g -std=c++11 maxsum.cpp -o maxsum -DDEBUG=1
 * Ref: https://en.wikipedia.org/wiki/Maximum_subarray_problem
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
//#ifdef DEBUG
#include "malib.h"
#include "segtree.h"
//#endif
using namespace std;

ull maxSum(std::vector<ull> &v, ull M) {
  const ull n = v.size();
 //auto it1 = std::max_element(v.begin(), v.end());
  ull maxSub= 0,subR = 0;
 
  for (ull i = 0; i < n; i++) {
    // Kadane’s algorithm on rows
    // greedy, restart if running sum < 0
    subR = (subR + v[i]) % M;
    maxSub = std::max({v[i] % M, subR, maxSub});
  }
/*  for (ull i = 0; i < n; i++) {
      if (v[i] < M )
        maxSub = std::max(v[i] % M, maxSub);
  }*/
  return maxSub;
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
/*
    std::sort(A.begin(), A.end());
     auto t = SegmentTree<ull>(A);
     t.build(Range::SUM, 1, 0, A.size() - 1);
     cout << "\nRMQ: " << t.rmq(Range::SUM, 0, A.size() - 1) %M<< endl;
     continue;   
  */
    cout << "Case:" << k + 1 << " " << maxSum(A, M) << endl ;
  }

  clock_t t1 = clock();
  printf("\nRuntime = %.4f s\n", (t1 - t0) / (double)CLOCKS_PER_SEC);
  return 0;
}
