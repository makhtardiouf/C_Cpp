/**
 *    author:  [itmo] enot.1.10
 *    created: 22.04.2016 21:11:12       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 1 << 17;
const ll INF = 1e18;


ll L[2 * N], R[2 * N], S[2 * N], M[2 * N];

inline void upd(int x)
{
    S[x] = max(-INF, S[2 * x] + S[2 * x + 1]);
    L[x] = max(L[2 * x], S[2 * x] + L[2 * x + 1]);
    R[x] = max(R[2 * x + 1], S[2 * x + 1] + R[2 * x]);
    M[x] = max(max(M[2 * x], M[2 * x + 1]), R[2 * x] + L[2 * x + 1]);
}

inline void UPD(int x, ll val)
{
    x += N;
    S[x] = val;
    M[x] = val;
    L[x] = val;
    R[x] = val;
    while (x > 1)
    {
        x >>= 1;
        upd(x);
    }
}



int a[N], b[N];
tuple<int, int, int> q[2 * N];
int qc = 0;

ll res[N];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d", a + i);
    forn(i, m) scanf("%d", b + i);
    forn(i, n) q[qc++] = make_tuple(a[i], 0, i);
    forn(i, m) q[qc++] = make_tuple(b[i], -1, i);

    forn(i, N) UPD(i, -INF);

    sort(q, q + qc);
    for (int i = qc - 1; i >= 0; --i)
    {
        int val, tt, pos;
        tie(val, tt, pos) = q[i];
        if (tt == 0)
        {   
            UPD(pos, val);
        }
        else
        {
            res[pos] = M[1];
            if (M[1] < -INF / 2) res[pos] = 0;
        }
    }
    forn(i, m) printf("%I64d%c", res[i], " \n"[i + 1 == m]);
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
