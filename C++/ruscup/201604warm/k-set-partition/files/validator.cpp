#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "testlib.h"

typedef long long ll;

using namespace std;

const int MAXN = 2000;

string itoa(int x) {
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	return s;
}

int main(int argc, char * argv[]) {
	registerValidation();

	int n = inf.readInt(1, MAXN, "n");
	inf.readSpace();
	int k = inf.readInt(1, MAXN, "k");
	inf.readEoln();
	for (int i = 0; i < n; i++) {
		int x = inf.readInt(1, n, "a[" + itoa(i) + "]");
		if (i == n - 1) inf.readEoln();
		else inf.readSpace();
	}
	inf.readEof();

	return 0;
}