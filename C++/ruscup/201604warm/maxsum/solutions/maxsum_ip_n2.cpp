#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;
#define TASK "maxsum"

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int j = 0; j < m; ++j) {
        int b;
        scanf("%d", &b);
        ll ans = numeric_limits<ll>::min();
        ll mn = 0, s = 0;
        for (int i = 0; i < a.size(); ++i) {
            s += a[i];
            if (a[i] < b)
                mn = s;
            else {
                ans = max(ans, s - mn);
                mn = min(mn, s);
            }
        }
        if (ans == numeric_limits<ll>::min()) printf("0 ");
        else printf(lld" ", ans);
    }
    return 0;
}