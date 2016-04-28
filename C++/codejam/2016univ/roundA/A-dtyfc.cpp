#include <bits/stdc++.h>
using namespace std;
long long a[60];

int Solve(long long x) {
	if(x == 1) return 0;
	for(int i = 60; i >= 0; i--) {
		if(a[i] < x) {
			if(x == a[i] + 1) return 0;
			return !Solve(a[i] - (x - a[i] - 1) + 1);
		} 
	}
}
int main() {
#ifdef youmu
	freopen("A-large.in", "r", stdin);
	freopen("A-large.ou", "w", stdout);
#endif
	for(int i = 0; i <= 60; i++) a[i] = (1LL << i) - 1;
	int T, cases = 0;
	long long K;

	cin >> T;
	while(T--) {
		cin >> K;
		printf("Case #%d: %d\n", ++cases, Solve(K));
	}
	return 0;
}
