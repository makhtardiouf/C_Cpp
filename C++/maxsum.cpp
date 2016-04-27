/*
 * $Id$
 * maximum value of (Sum of Subarray ) %M
 * Author: makhtar
 * This version is slow on large N
 * c++ -g -std=c++11 maxsum.cpp -o maxsum -DDEBUG=1
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#ifdef DEBUG
#include "malib.h"
#endif

using namespace std;

int maxSum(std::vector<int> &v, int M)
{
    int n = v.size();
    // lowest possible value
    int maxSub = 0;
    int subR = 0;

    for (int c = 0; c < n; c++) {
        subR += v[c];
        // Kadane’s algorithm on rows
        if (subR < 0)
            subR = 0;

        // greedy, restart if running sum < 0
        maxSub = std::max(maxSub, subR % M);
    }
    return maxSub;
}

int main()
{
    int nCases;
    cin >> nCases;

    for (int k = 0; k < nCases; k++) {
        int N, M = 0;
        cin >> N >> M;
        std::vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        #ifdef DEBUG
            printV(A);
         #endif
         
        int ans = maxSum(A, M);
        // clog << ans << " % " << M << ": " ;
        cout << ans << endl;
    }

    return 0;
}
