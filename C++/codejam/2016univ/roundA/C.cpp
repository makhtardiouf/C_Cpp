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

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

LL p[200][200], q[200][200];

struct edge {
    LL u, v, c;
};
void solve() {
    int n , m;
    cout << endl;
    vector<int> res;
    cin >> n >> m;
    vector<edge> v(m);
    for (int i = 0; i < m; i ++)
        cin >> v[i].u >> v[i].v >> v[i].c;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            p[i][j] = 1ll << 31;
        }
    for (int i = 0; i < n; i ++) p[i][i] = 0;
    for (auto e : v) p[e.u][e.v] = min(p[e.u][e.v], e.c), p[e.v][e.u] = min(p[e.v][e.u], e.c);
    for (int k = 0; k < n; k ++)
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
    int cnt = 0;
    for (int i = 0; i < m; i ++) 
        if (p[v[i].u][v[i].v] < v[i].c) {
            cnt ++;
            cout << i << endl; 
    }
    //cerr << cnt << '/' << m << endl;
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
