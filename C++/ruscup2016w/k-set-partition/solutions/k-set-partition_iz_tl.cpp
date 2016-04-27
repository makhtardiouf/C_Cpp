#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1000 * 1000 * 1000 + 7;

int fastsolve(vector<int> a, int k) {
	int n = a.size();
	map<int, int> mp;
	for (int i = 0; i < n; i++) mp[a[i]]++;
	vector<int> cnt;
	for (auto it : mp) cnt.push_back(it.second);
	int m = cnt.size();

	// divide numbers 1..n to k sets
	vector<vector<int> > dp1(n + 1, vector<int>(k + 1, 0));
	dp1[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp1[i][j] = (dp1[i - 1][j] * 1LL * j + dp1[i - 1][j - 1]) % MOD;
		}
	}

	// divide first m blocks to k groups, last can or not be extended
	vector<vector<vector<int> > > dp2(m + 1, vector<vector<int> >(k + 1, vector<int>(2, 0)));
	dp2[0][0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp2[i][j][0]) {
				int o = 0;
				for (int l = 1; l <= cnt[i]; l++) if (j + l <= k) {
					dp2[i + 1][j + l][0] = (dp2[i + 1][j + l][0] + 1LL * dp2[i][j][o] * dp1[cnt[i]][l]) % MOD;
					dp2[i + 1][j + l][1] = (dp2[i + 1][j + l][1] + 1LL * dp2[i][j][o] * dp1[cnt[i]][l] % MOD * l) % MOD;
				}
			}
			if (dp2[i][j][1]) {
				int o = 1;
				for (int l = 1; l <= cnt[i]; l++) if (j + l - 1 <= k) {
					dp2[i + 1][j + l - 1][0] = (dp2[i + 1][j + l - 1][0] + 1LL * dp2[i][j][o] * dp1[cnt[i]][l] % MOD * l) % MOD;
					dp2[i + 1][j + l - 1][1] = (dp2[i + 1][j + l - 1][1] + 1LL * dp2[i][j][o] * dp1[cnt[i]][l] % MOD * l % MOD * max(1, l - 1)) % MOD;
				}
			}
		}
	}
	return dp2[m][k][0];
}

int slowsolve(vector<int> a, int k) {
	int n = a.size();
	vector<int> b(n, -1);
	int ans = 0;
	function<void(int)> f = [&](int x) {
		if (x == k) {
			bool bad = 0;
			for (int i = 0; i < n; i++) if (b[i] == -1) bad = 1;
			if (bad) return;
			vector<int> mn(k, n + 1), mx(k, -1);
			for (int i = 0; i < n; i++) {
				mn[b[i]] = min(mn[b[i]], a[i]);
				mx[b[i]] = max(mx[b[i]], a[i]);
			}
			bool ok = 1;
			for (int i = 0; i < k; i++) {
				for (int j = i + 1; j < k; j++) {
					ok &= mx[i] <= mn[j] || mx[j] <= mn[i];
				}
			}
			ans += ok;
			return;
		}
		vector<int> vct;
		for (int i = 0; i < n; i++) if (b[i] == -1) vct.push_back(i);
		for (int mask = 1; mask < (1 << (int)vct.size()); mask += 2) {
			for (int i = 0; i < (int)vct.size(); i++) {
				if (mask & (1 << i)) {
					b[vct[i]] = x;
				}
			}
			f(x + 1);
			for (int i = 0; i < (int)vct.size(); i++) {
				if (mask & (1 << i)) {
					b[vct[i]] = -1;
				}
			}
		}
	};
	f(0);
	return ans;
}

void print(vector<int> a) {
	for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " \n"[i + 1 == (int)a.size()];
}

void stress() {
	for (int it = 0;; it++) {
		cerr << it << endl;
		int n = rand() % 10 + 1;
		int k = rand() % n + 1;
		vector<int> a(n);
		for (int i = 0; i < n; i++) a[i] = rand() % n + 1;
		int ans1 = fastsolve(a, k);
		int ans2 = slowsolve(a, k);
		if (ans1 != ans2) {
			cout << ans1 << " instead if " << ans2 << endl;
			cout << n << " " << k << endl;
			print(a);
			fastsolve(a, k);
			exit(0);
		}
	}
}

int main() {
	int n, k;
	while (cin >> n >> k) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << slowsolve(a, k) << endl;
	}

	return 0;
}