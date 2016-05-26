/**
 *    author:  [itmo] enot.1.10
 *    created: 22.04.2016 23:32:59       
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

const int N = 110;

char s[N];
char t[N];

int have[256];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    scanf("%s", s);
    int n = strlen(s);
    forn(i, n) have[(int)s[i]] = 1;
    int q;
    scanf("%d", &q);
    forn(_, q)
    {
        scanf("%s", t);
        int cnt1 = 0;
        forn(i, n) if (s[i] == t[i]) cnt1++;
        int cnt2 = 0;
        forn(i, n) if (have[(int)t[i]]) cnt2++;
        printf("%d %d\n", cnt1, cnt2 - cnt1);
    }
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
