/**
 * Makhtar Diouf
 * Google Japan University Graduate 20160301 Tests
 * 
 * Compile: g++ -g -Wall -std=c++11 a.cpp -o a
 * Run: ./a < A-small-practice.in
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
#define SZ 4  // matrix row/col size

int solve() {
    
}

int main(int argc, char* argv[]) {
    int T = 0;      // num of test cases
    cin >> T;
    clog << T << " test cases\n";    
    
    for (int i = 0; i < T; ++i) {
        input >> K;        
        clog << "K = " << K << "\n";
        
        
        cout << "Case #" << i + 1 << ": " << solve() << "\n";
    }
    
    return 0;
}