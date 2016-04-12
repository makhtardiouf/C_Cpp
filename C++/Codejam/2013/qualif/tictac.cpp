/* 
 * Author: makhtar
 * https://code.google.com/codejam/contest/2929SZ86/dashboard#s=p0
 * Created on Februarv 28, 2016, 11:55 PM
 * g++ -g -std=c++11 tictac.cpp -o tictac
 */
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
#define SZ 4

string
solve(vector<char> b[21]) {
    char vch[] = {'X', '0'};
    stringstream ss;
    for (auto ch : vch) {
        bool wind1 = true; // diagonal 1
        bool wind2 = true;

        for (int x = 0; x < SZ; x++) {
            bool gotRow = true; // horizontal = row
            bool gotCol = true; // vertical = col

            for (int y = 0; y < SZ; y++) {
                // Check rows & cols
                ss << b[x][y] << " " << b[y][x] ;
                 clog << ss.str();
               // clog << "ch= " << ch << endl;
                if ((b[x][y] != ch) && (b[x][y] != 'T')) gotRow = false;
                if ((b[y][x] != ch) && (b[y][x] != 'T')) gotCol = false;
            }
            clog << endl;
            ss.clear();
            if (gotRow || gotCol) {
                ss << ch << " won";
                return ss.str();
            }

            // Check Diagonals [0, 0] [1, 1]...
            if ((b[x][x] != ch) && (b[x][x] != 'T')) wind1 = false;

            if ((b[3 - x][x] != ch) && (b[3 - x][x] != 'T')) wind2 = false;
        }
        if (wind1 || wind2) {
            ss << ch << " won";
            return ss.str();
        }
    }

    for (int x = 0; x < SZ; x++) {
        for (int y = 0; y < SZ; y++)
            if (b[y][x] == '.') return "Game has not completed";
    }

    return "Draw";
}

int
main(int argc, char** argv) {
    int T = 0; // num of test cases
    cin >> T;
    clog << T << " test cases\n";

    int n = 21; //SZ * SZ;
    char ch;
  
    for (int c = 0; c < T; ++c) {
        vector<char> rows[n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            ch = cin.get();
            if (!isspace(ch)) {
                rows[j].push_back(ch);
                j++;
            }
            cerr << ch ;
        }
        ch = cin.get();
        clog << rows[0].size() << endl;

        string resp = solve(rows);
        cout << "Case #" << c + 1 << ": " << resp << endl;     
    }

    return 0;
}

