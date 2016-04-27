/*
 * maximum value of (Sum of Subarray ) %M
 * Author: makhtar
 * $Id$
 * This version is slow on large N
 * c++ -g -std=c++11 maxsum.cpp -o maxsum
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//#include "malib.h"

using namespace std;

int maxSum(std::vector<int> &v, int M) {
  int n = v.size();

  // lowest possible value
  int maxSubRect = 0;

 // for (int r = 0; r < n; r++) {
    int subRect = 0;

    for (int c = 0; c < n; c++) {

      subRect += v[c];
      // Kadane’s algorithm on rows
      if (subRect < 0)
        subRect = 0;

      // greedy, restart if running sum < 0
      maxSubRect = std::max(maxSubRect, subRect % M);
    }
//  }
  return maxSubRect;
}

int main() {
  int nCases;
  cin >> nCases;

  for (int k = 0; k < nCases; k++) {
    int N, M = 0;
    cin >> N >> M;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    // printV(A);
    int ans = maxSum(A, M);
    // cout << ans << " % " << M << ": " ;
    cout << ans << endl;
  }

  return 0;
}
