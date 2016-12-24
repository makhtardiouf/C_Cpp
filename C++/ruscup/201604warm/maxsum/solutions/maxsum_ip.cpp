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
const ll NEG_INF = numeric_limits<ll>::min();

struct Dsu {
    int n;
    vector<int> p, rank, left, right;
    Dsu(int n):n(n), p(n), rank(n), left(n), right(n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            right[i] = -1;
        }
    }

    void init(int v) {
        left[v] = v;
        right[v] = v;
    }

    int leftB(int v) {
        return left[root(v)];
    }

    int rightB(int v) {
        return right[root(v)];
    }

    bool isInited(int v) {
        return v >= 0 && v < n && right[v] != -1;
    }

    int root(int v) {
        return v == p[v] ? v : p[v] = root(p[v]);
    }

    void join(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n)
            return;
        x = root(x);
        y = root(y);
        if (!isInited(x) || !isInited(y))
            return;
        if (rank[x] < rank[y])
            swap(x, y);

        p[y] = x;
        rank[x] += rank[x] == rank[y];
        left[x] = min(left[x], left[y]);
        right[x] = max(right[x], right[y]);
    }
};

template <class T>
struct IntTree {
    int size;
    vector<T> t;
    template <class Iterator>
    IntTree(Iterator first, Iterator last):size(distance(first, last)), t(2 * size){
        for (int i = 0; i < size; ++i, first++)
            t[i + size] = *first;

        for (int i = size - 1; i >= 0; --i)
            t[i] = max(t[2 * i], t[2 * i + 1]);
    }

    T getMax(int l, int r) {
        l += size;
        r += size;
        T ret;
        if (l < size) {
            ret = 0;
            l++;
        } else
            ret = t[l];

        while (l <= r) {
            if (l&1) ret = max(ret, t[l++]);
            if ((r&1) == 0) ret = max(ret, t[r--]);
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};

struct Event {
    int tp, pos, val;
    Event() {}
    Event(int tp, int pos, int val): tp(tp), pos(pos), val(val) {}
    bool operator < (const Event& e) const {
        return val < e.val || val == e.val && tp < e.tp;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<Event> a(n + m);
    vector<ll> s(n), sneg(n), ans(m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s[i] = (i == 0 ? 0 : s[i - 1]) + x;
        sneg[i] = -s[i];
        a[i] = Event(1, i, x);
    }
    IntTree<ll> tree(s.begin(), s.end());
    IntTree<ll> treeNeg(sneg.begin(), sneg.end());
    int x;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        a[i + n] = Event(0, i, x);
    }
    sort(a.begin(), a.end());
    Dsu dsu(n);

    ll curAns = NEG_INF;

    for (int i = (int)a.size() - 1; i >= 0; --i)
        if (a[i].tp) {
            dsu.init(a[i].pos);
            dsu.join(a[i].pos - 1, a[i].pos);
            dsu.join(a[i].pos, a[i].pos + 1);
            int root = dsu.root(a[i].pos);
            ll cur1 = s[a[i].pos] + treeNeg.getMax(dsu.left[root] - 1, a[i].pos - 1);
            curAns = max(curAns, cur1);
            if (dsu.isInited(a[i].pos + 1)) {
                ll cur2 = tree.getMax(a[i].pos + 1, dsu.right[root]) + treeNeg.getMax(dsu.left[root] - 1, a[i].pos);
                curAns = max(curAns, cur2);
            }
        } else {
            if (curAns != NEG_INF)
                ans[a[i].pos] = curAns;
        }

    for (int i = 0; i < m; ++i)
        if (i + 1 != m)
            printf(lld" ", ans[i]);
        else
            printf(lld"\n", ans[i]);

    return 0;
}