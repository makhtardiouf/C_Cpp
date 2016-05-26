/**
Classic coin change problem,
Use Dynamic Programming to cache computed data in a memo table
Makhtar Diouf

Hrank: output number of ways we could make the change
https://www.hackerrank.com/challenges/coin-change
c++ -g -std=c++11 coinschange.cpp -o coinschange
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ll N =0, M = 0;
  cin >> N >> M;
  
  ll val = 0;
  vector<ll> coins;
  for (ll i = 0; i < M; i++) {
    cin >> val;
    coins.push_back(val);
  }

vector<ll> memo(M + 1);
  memo[0] = 1;
  
  for (ll i = 1; i <= N ; i++)
    for (ll j = 1; j <= M ; j++)
      if (j >= coins[i - 1])
        memo[j] += memo[j - coins[i - 1]];

  printf("%lld\n", memo[memo.size() -1]);

  return 0;
}
