/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
double A[1000000 + 5];
lld len[1000000 + 5];

int rec(lld K) {
    int it = 0;
    for (int i = 0; i <= 60; ++i) {
        if (len[i] >= K) {
            it = i;
            break;
        }
    }
    if (len[it - 1] + 1 == K)
        return 0;
    lld dist = len[it] - K + 1;
    return rec(dist)^1;
}

int solve() {
    lld K;
    cin>>K;
    len[0] = 0;
    for (int i = 1; i <= 64; ++i) {
        len[i] = 2 * len[i - 1] + 1;
    }
    return rec(K);
}

int main() {
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);

    int T, test = 0;
    cin>>T;

    while (T--) {
        test++;
        printf("Case #%d: %d\n", test, solve());
    }
}
