#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "testlib.h"

typedef long long ll;

using namespace std;

const int MAXN = 2000;
int cur_test = -1;

const vector<pair<int, vector<int> > > hand_tests = vector<pair<int, vector<int> > >({
	make_pair(2, vector<int>({1, 2, 3})),
	make_pair(3, vector<int>({2, 4, 3, 4, 3, 3, 2})),
	make_pair(1, vector<int>({1})),
	make_pair(2, vector<int>({1})),
	make_pair(3, vector<int>({1, 1, 1, 1, 1})),
	make_pair(3, vector<int>({5, 4, 2, 1, 3})),
	make_pair(4, vector<int>({3, 2, 1, 2, 1, 3, 3, 2, 1})),
	make_pair(2000, vector<int>({1}))
});

string itoa(int x) {
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	return s;
}

int atoi(string s) {
	stringstream ss;
	int x;
	ss << s;
	ss >> x;
	return x;
}

void write_test(int k, vector<int> a) {
	startTest(cur_test++);
	int n = a.size();
	cout << n << " " << k << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i + 1 == n];
	}
}

void gen_rand(int n, int mx, int k) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = rnd.next(mx) +1;
	}
	write_test(k, a);
}

int main(int argc, char * argv[]) {
	registerGen(argc, argv, 1);
	cur_test = atoi(argv[1]);

	for (int i = 0; i < (int)hand_tests.size(); i++) {
		write_test(hand_tests[i].first, hand_tests[i].second);
	}

	gen_rand(MAXN - 67, 123, 123);
	gen_rand(MAXN, MAXN / 2, 1);
	gen_rand(MAXN, MAXN / 10, MAXN);
	gen_rand(MAXN, 5, 10);
	gen_rand(MAXN, 5, MAXN / 2);
	gen_rand(MAXN, 37, 160);
	gen_rand(MAXN, 65, 1577);
	gen_rand(MAXN, 666, 1874);
	gen_rand(MAXN, 32, 1768);
	gen_rand(MAXN, 2, 1998);
	gen_rand(MAXN, 1965, 1977);
	gen_rand(MAXN, 341, 1500);

	return 0;
}