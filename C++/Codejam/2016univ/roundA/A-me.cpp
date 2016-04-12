#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

/**
 g++ -std=c++11 A-me.cpp -o A-me
 */
using namespace std;

long long N = 10^100;

int fun(long long K) {
    // reverse
    if ((K & (K - 1)) == 0)
        return 0;

    int a = 1;
    while (K >= a)
        a <<= 1;

    // Switch the bits
    return 1 ^ fun(a - K);
}

template <size_t sz>
std::bitset<sz> func(std::bitset<sz> b) {
    vector<int> v;
    for (int i = 0; i < b.size(); i++)
        v.push_back(b[i]);

    int Sn_1 = b[b.size() - 1];
    std::reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        b[i] = v[i];

    b.flip();
    return b;
    // Switch and reverse

}


int proc(long long x) {
    if(x == 1)
        return 0;
    
string s;
int i = 1;
std::bitset<sizeof(long long)> b(i);
    for (; i < N; i++) {
        
        int Sn_1 = b[b.size() - 1];

        std::bitset<sizeof(long long)> c = func(b);
        s = Sn_1 + "0" + c.to_string();
        b = std::bitset<sizeof(long long)>(s);
        cout << s << endl;
    }
return s[x];
}

int main(int argc, char* argv[]) {

    int T = 0; // num of test cases 1 ≤ T ≤ 100
    long long K = 0; // Kth character of Sgoogol 1 ≤ K ≤ 10^5 or 10^18

    clog << "Reading input file " << argv[1];
    string s{argv[1]};
    std::ifstream input{s}; // input stream   
    input >> T;
    clog << "  " << T << " tests cases\n";

    for (int i = 0; i < T; ++i) {
        input >> K;
        clog << "K = " << K << "\n";

          cout << "Case #" << dec << i + 1 << ": " << proc(K) << "\n";
    }

    return 0;
}
