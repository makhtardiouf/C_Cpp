/**
 * $Id$
 * Author: Makhtar Diouf
 * Google codejam:  run with ./str_reversewords B-small-practice.in
 * https://code.google.com/codejam/contest/351101/dashboard#s=p1
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void reversevect(vector<string> v) {
    static int iterNum = 1;
    std::reverse(v.begin(), v.end());
    cout << "Case #" << iterNum << ": ";
    iterNum++;
    for (string s : v)
        cout << s << " ";

    cout << "\n";
}

int main(int argc, char** argv) {
    // cout << "Reading input file...\n";
    vector<string> v;
    string s(argv[1]);
    std::ifstream is(s); // input stream

    char c;
    s = "";
    char dust[10];
    is.getline(dust, 10); // skip first num
    
    while (!is.eof()) {
        c = is.get();
        if (isspace(c)) {
            // Only add the word once we reach Space of Newline
            v.push_back(s);
            s = "";
        } else
            s += c;

        if (c == '\n') {
            reversevect(v);
            v.clear();
            s = "";
        }
    }

}

