#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const int N = 300;
string ch;
int n;
int cnt[N];

void init() {
	for (int i = 0; i < N; i++) {
		cnt[i] = 0;	
	}
}

int main() {
	init();
	cin >> ch;
	for (size_t i = 0; i < ch.size(); i++) {
		cnt[ch[i]]++;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cur;
		cin >> cur;
		int bull = 0;
		int cow = 0;
		int m = (int)cur.size();
		for (int j = 0; j < m; j++) {
			int num = cur[j];
			if (ch[j] == cur[j]) {
				bull++;
			}
			if (cnt[num] > 0 && ch[j] != cur[j]) {
				cow++;
			}
		}
		cout << bull << " " << cow << endl;
	}
}