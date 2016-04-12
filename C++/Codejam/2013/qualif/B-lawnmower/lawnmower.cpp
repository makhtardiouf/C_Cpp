/* 
 * Author: makhtar
 * https://code.google.com/codejam/contest/2270488/dashboard#s=p1
 * Created on March 9, 2016, 11:39 PM
 * Compile g++ -std=c++11 -g -Wall lawnmower.cpp -o lawnmower
 * 
 * Lawn in front of the house, N * M meters rectangle shaped 
 * Set it to any height h between 1 and 100 milli, and it will cut all 
 * the grass higher than h. h can be set only when it is not on the lawn.
 * The grass is initially 100mm high on the whole lawn
 */
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int N, M = 0;

inline string
solve(const vector< vector<int> > t) {
   
    for (int i = 0; i < N; i++) {
        //  int max = *(std::max_element(rows[i].begin(), rows[i].end()));
        for (int j = 0; j < M; j++) {
            int c = t[i][j];

            bool ok = true;
            // check rows
            for (int k = 0; k < N; ++k) {
                if (t[k][j] > c) {
                    ok = false;
                    break;
                }
            }
            if (ok) continue;

            ok = true;
            // check columns
            for (int k = 0; k < M; ++k) {
                if (t[i][k] > c) {
                    ok = false;
                    break;
                }
            }
            if (!ok) return "NO";
        }
    }

    return "YES";
}

int
main(int argc, char** argv) {
    int T = 0;
    string fname = "B-small-practice.in";
    ifstream input(fname);
    ofstream outp(fname+ ".out");
    
    input >> T;
    clog << T << " test cases\n";

    for (int c = 1; c <= T; ++c) { 
        input >> N >> M;
        clog << "N=" << N << ", " << " M=" << M << "\n";

        // 1 ≤ a(i,j) ≤ 2 or 100
        // Clang++ complains if using rows[sz] here: length array of non-POD element type

        vector< vector<int> > rows(N, vector<int>(M));
        int val = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                input >> val;
                rows[i][j] = val;
                clog << val << " ";
            }
            clog << endl;
        }

        outp << "Case #" << c << ": " << solve(rows) << endl;
    }

    return 0;
}

