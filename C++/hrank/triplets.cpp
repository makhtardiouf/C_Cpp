/**
HRANK Triplets
c++ -g -std=c++11 triplets.cpp  -o triplets
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

int solve(vector<int> &v, int d) {
  int n = v.size();
  int trip = 0;
  bool t1 = false, t2 = false;
  // for(int i = n-1; i >= 0; i++)
  for (int i = n - 1; i >= 0; i--) {

    for (int j = i - 1; j >= 0; j--) {
      if ((v[i] - v[j]) == d) {
        if (!t1)
          t1 = true;

        for (int k = j - 1; k >= 0; k--) {
          if ((v[j] - v[k]) == d) {
            trip++;
            fprintf(stderr, "\nmatch: (%d, %d, %d)\n", v[i], v[j], v[k]);
            break;
          }
        }
        break;
      }
    }
  }
  return trip;
}

int main() {

  int n = 0, d = 0, nl;
  cin >> n >> d;
  // cin >> nl; // throw new line

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  cout << solve(v, d) << endl;

  return 0;
}
