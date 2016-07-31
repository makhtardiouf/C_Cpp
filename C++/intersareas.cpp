/**
 * RT E-Level
 * Makhtar Diouf
  K < M;  L < N; P < R; Q < S;
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int solution2(int K, int L, int M, int N, int P, int Q, int R, int S) 
 {
    int b = max(L, Q);
    int t = min(N, S);
     int l = max(K, P);
    int r = min(M, R);

    if (l < r && b < t) {
        int overlap = (r - l) * (t - b);
        int total = ((M - K) * (N - L)) + ((R - P) * (S - Q))
                - overlap;
        return total;
    }
    return -1;
 }

int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {

  ll area1 = (ll)((M - K) * (N - L));
  ll area2 = (ll)((R - P) * (S - Q));
  ll tot = area1 + area2;

  // overlapping area
  if ((P < M) && (L < S)) {
    //  clog << "P < M\n";
    ll subA1 = (ll)((min(M, R) - max(K, P)) * (min(N, S) - max(L, Q)));
    //(ll)((M - P) * (S - L));
    tot -= subA1;
  }

  if (tot > numeric_limits<int>::max())
    return -1;

  return tot;
}

int main() {

  // out = 42
  int tot = solution(-10, -10, 0, 0, -1, -1, 2, 2);
  printf("Area: %d\n", tot);
  printf("Max %d\n", numeric_limits<int>::max());
  cout << (tot == numeric_limits<int>::max()) << endl;
  return 0;
}
