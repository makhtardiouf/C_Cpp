#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "testlib.h"

typedef long long ll;

using namespace std;

const int MAXN = (int)1e5;
const int MAXX = (int)1e9;
int cur_test = -1;

const vector<vector<int>> hand_tests = vector<vector<int>> ({
    vector<int>({1, 2, 3, 4, 5}),
    vector<int>({1, 2, 3, 4, 4}),
    vector<int>({1, 2, MAXX}),
    vector<int>({1, 1, 1, 1, 1}),
    vector<int>({MAXX, 1, MAXX, 1, MAXX}),
    vector<int>({MAXX / 2, 1, MAXX / 3, 1, MAXX / 3}),
    vector<int>({3, 2, 1, 2, 1, 3, 3, 2, 1}),
    vector<int>({MAXX, MAXX, MAXX})
});

string itoa(int x) 
{
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    return s;
}

int atoi(string s) 
{
    stringstream ss;
    int x;
    ss << s;
    ss >> x;
    return x;
}

void write_test(vector<int> a) 
{
    startTest(cur_test++);
    int n = a.size();
    cout << n << endl;
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << endl;
}

void gen_rand(int n, int mx) 
{
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        a[i] = rnd.next(mx) + 1;
    write_test(a);
}

int main(int argc, char * argv[]) 
{
    registerGen(argc, argv, 1);
    cur_test = atoi(argv[1]);

    for (int i = 0; i < (int)hand_tests.size(); i++) 
        write_test(hand_tests[i]);

    for (int i = 10; i <= MAXN; i *= 10)
    {
        int n = rnd.next(i / 2) + i / 2;
        gen_rand(n, i);
        
        n = rnd.next(i / 2) + i / 2;
        gen_rand(n, MAXX);

        gen_rand(i, MAXX);

    }

    return 0;
}