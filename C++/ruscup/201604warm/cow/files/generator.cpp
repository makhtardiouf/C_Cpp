#include "testlib.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <set>


using namespace std;

const int N = 100000;
const int M = 10;
/*
<#assign maxN = 50/>
<#list 1..100 as testNumber>
    generator ${testNumber} ${maxN} > $
</#list>
*/

int main(int argc, char* argv[]) {
	registerGen(argc, argv);
	string main_str = "";
	for (int i = 0; i < 10; i++) main_str += (char)(i + '0');
	for (int i = 0; i < 26; i++) main_str += (char)(i + 'A');
	int m = atoi(argv[2]);
	int nn = atoi(argv[3]);
	int n = rnd.next(1, nn);
	shuffle(main_str.begin(), main_str.end());
	string ss = main_str.substr(0, m);
	cout << ss << endl;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		int hm = rnd.next(0, 5);
		string cur;
		if (hm < 2) {
			shuffle(main_str.begin(), main_str.end());
			cur = main_str.substr(0, m);
		} else {
			int a = rnd.next(0, max(0, (int)ss.size() - 3));
			int b = rnd.next(3, max(3, (int)ss.size() - a));
			cur = ss;
			shuffle(cur.begin() + a, cur.begin() + a + b);
		}
		if (i == n - 1) cur = ss;
		cout << cur << endl;		
	}
    
    return 0;
}