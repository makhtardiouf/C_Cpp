#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
//******* 2016 Round A
using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

int f(LL x) {
    if ((x & (x - 1)) == 0) return 0;
    int a = 1;
    while (x >= a) a <<= 1;
    return 1 ^ f(a - x);
}


void solve() {
    LL n;
    cin >> n;
    cout << f(n) << endl;
}

int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int Q; cin >> Q;
    for (int i = 0; i < Q; i ++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }    
    return 0;
}
