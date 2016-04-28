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

//typedef long double double;
typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second
#define double long double


LL p[5000];
double l[5000];
void solve() {
    cout <<  endl;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> p[i], l[i] = log10((double)(p[i]));
    l[0] = 0;
    for (int i = 1; i <= n; i ++) l[i] += l[i - 1];
    for (int i = 0; i < m; i ++) {
        int a, b; cin >> a >> b;
        cout << setprecision(10) << fixed << pow((double)10, (l[b + 1] - l[a]) / (b - a + 1))<< endl;
    }
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
