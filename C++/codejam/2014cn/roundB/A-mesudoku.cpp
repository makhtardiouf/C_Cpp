/* 
 * Author: makhtar
 * https://code.google.com/codejam/contest/2929486/dashboard#s=p0
 * Created on Februarval 28, 2016, 11:55 PM
 * g++ -g -std=c++11 A-mesudoku.cpp -o A-mesudoku
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>

#include <cmath>
#include <cstdlib>
#include <cstring>


using namespace std;

bool check(vector<int> v) {
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        // v[0] = 1, v[1] = 2
        if (v[i] != i + 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {

    int T = 0; // num of test cases 1 ≤ T ≤ 100
    int N = 0; // Matrixes size 3 ≤ N ≤ 6.

    clog << "Reading input file " << argv[1];
    string s{argv[1]};
    std::ifstream input{s}; // input stream   
    input >> T;
    clog << "  " << T << " tests cases\n";

    int val = 0;

    for (int c = 0; c < T; ++c) { /// tmp
        input >> N;
        clog << "N = " << N << "\n";
        int sz = N*N;

        std::map<int, int> rows[sz];
        // vector< vector<int> > vrows(sz, vector<int>sz);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                input >> val;
                rows[i][j] = val;
                clog << val << " ";
            }
            clog << endl;
        }

        bool flag = true;
        for (int i = 0; i < sz; i++) {
            vector<int> v;
            clog << "Row " << i << ": ";
            for (int j = 0; j < sz; ++j) {
                val = rows[i][j];
                v.push_back(val);
                clog << val << " ";
            }
            clog << endl;
            flag = flag && check(v);

            clog << "Flag: " << flag << endl;
            if (!flag)
                break;
        }

        // Check columns  if still valid       
        for (int i = 0; i < sz; i++) {
            vector<int> v;
            clog << "Col " << i << ": \n";

            for (int j = 0; j < sz; j++) {
                val = rows[j][i];
                v.push_back(val);
                //   clog << val << "\n";
            }
            //  clog << endl;
            flag = flag && check(v);
            if (!flag)
                break;
        }

        clog << "Flag: " << flag << endl;

        // Check Submatrixes if still valid

        if (flag) {
            int n = N;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    vector<int> v;

                    for (int x = 0; x < n; ++x) {
                        clog << "Sub row " << x << ": ";

                        for (int y = 0; y < n; ++y) {
                            val = rows[i * n + x][j * n + y];
                            v.push_back(val);
                            clog << val << " ";
                        }
                        clog << endl;
                    }

                    flag = flag && check(v);
                    if (!flag)
                        break;
                }
            }
        }
        cout << "Case #" << c + 1 << ": ";
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";

        //  clog << "\nSum: " << std::accumulate(vrows[0].begin(), vrows[0].end(), 0);
    }

    return 0;
}
