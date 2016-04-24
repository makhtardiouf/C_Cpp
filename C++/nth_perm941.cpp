/**
   Return the (N+1)th permutation of a string
   https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=882
   g++ -std=c++11 nth_permutation941.cpp -o nth_permutation
   ./nth_permutation < n1th-test.in
   Makhtar Diouf $Id$
*/

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

uint64_t fact[20];

void solve(string s, uint64_t N) {
  //  std::next_permutation(s.begin(), s.end());
  
  for (int i = 0, sz = s.size(); i < sz; i++) {
    int next = 0;
    // cannot use sz here
    while (fact[s.size() - 1] < N+1) {
      N -= fact[s.size() - 1];
      next++;
    }
    cout << s[next];
    s.erase(s.begin() + next);
  }
  cout  << "\n";
}

int main()
{
  int T = 0;
  cin >> T;
  clog << T << " test cases\n";

  // Compute the factorials
  fact[0] = 1;
  for (int i = 1; i < 20; i++) {
    fact[i] =  fact[i-1] * i;
  }

  std::string s;
  uint64_t N = 0;
  for (int c = 0; c < T; ++c) {
    cin >> s; cin >> N;
    std::sort(s.begin(), s.end());
    clog << s << ", " << N << " -> ";
    solve(s, N);
  }
}
