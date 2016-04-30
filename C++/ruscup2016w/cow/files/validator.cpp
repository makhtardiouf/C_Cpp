#include "testlib.h"
using namespace std;

const int N = 300;
int n;
bool used[N];


bool ok(string s) {
	for (int i = 0; i < N; i++) used[i] = false;
	for (size_t i = 0; i < s.size(); i++) {
		if (used[s[i]]) return false;
		used[s[i]] = true;
	}
	return true;
}


int main() {
    registerValidation();
    std::string ss;
    ss = inf.readToken("[0-9A-Z]{1, 36}");
    ensuref(ok(ss), "chars are not different"); 	
    size_t m = ss.size();
    inf.readEoln();
    n = inf.readInt(1, 100000);
    inf.readEoln();
    for (int i = 0; i < n; i++) {
		std::string cur;
		cur = inf.readToken("[0-9A-Z]{1, 36}");
		ensuref(cur.size() == m, "lengths are different"); 	
		ensuref(ok(cur), "chars are different");
		inf.readEoln();	
    }
    inf.readEof();
    return 0;
}