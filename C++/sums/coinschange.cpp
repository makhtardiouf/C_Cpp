/**
Classic coin change problem, using Dynamic Programming
Makhtar Diouf

Hrank number of ways we could make the change
https://www.hackerrank.com/challenges/coin-change
c++ -g -std=c++11 coinschange.cpp -o coinschange
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector< vector<ll> > vvi;

vector<ll> coins;
//vvi memo;
ll N = 0, mem = 0;

ll ways(ll c, ll amount, vvi& memo)
{
    // mem = 0;
    mem = memo[c][amount];
    clog << "\nc, mem: " << coins[c] << " " << mem << endl;

    if (amount == 0)
        return 1;
    else if (amount < 0 || c < 0)
        return 0;
    else if (memo[c][amount] != -1)
        clog << "\nmem hit\n"; //return memo[c][amount];

    if(amount % coins[c] == 0) {
        mem++;       
    }

    for(ll i=0; i < coins.size(); i++) {
        if((coins[c] + coins[i]) == amount) {
            mem++;
            fprintf(stderr, "\nSum hit: %lld %lld\n", c, i);
        }
    }
    // avoid reusing this coin
    //coins[c] = 0;
    clog << "\nc, mem: " << coins[c] << " " << mem << endl;
    if(c < coins.size()-1)
        return memo[c][amount] = mem + ways(coins[c + 1], amount - coins[c], memo);
    return mem;
}

int  main()
{
    ll M = 0;
    cin >> N >> M;
    vvi memo(N+1, vector<ll>(M+1));
    // memo = mtmp;

    for(auto m: memo)
        m.assign(M*M, -1);
    // memset((void*)m, -1, sizeof m);

    int val = 0;
    for(ll i=0; i < M; i++) {
        cin >> val;
        coins.push_back(val);
    }

    printf("%lld\n", ways(0, N, memo));
    return 0;
}
