/*
HRK jump could

If ci=0, the ith cloud is an ordinary cloud. (co, cn-1 always OC)
If ci=1, the ith cloud is a thundercloud. FORBIDDEN
Number of jump to win @  cn-1 or co
c++ -g -std=c++11 jumpclouds.cpp  -o jumpclouds
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solve(vector<int> &v) {
  int numJumps = 0;
  int n = v.size();
  for (int i = 0; i < n; i++) {
    if ((i <= n - 2) && (v[i + 2] == 0)) {
      numJumps++;
      i += 1;
    } else if ((i < n - 1) && v[i + 1] == 0)
      numJumps++;
  }

  return numJumps;
}

int main() {
  int n = 0;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  cout << solve(v) << endl;

  return 0;
}