/**
 * $Id$
 * Author: Makhtar Diouf
 * Compilation g++ -std=c++11 -g -Wall str_reversewords.cpp malib2.cpp -o str_reversewords
 * Google codejam:  run with ./str_reversewords B-small-practice.in
 * https://code.google.com/codejam/contest/351101/dashboard#s=p1
 */
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include "malib.h"

using namespace std;

void reversevect(vector<string> v) {
    static int i = 1;
    std::reverse(v.begin(), v.end());
    cout << "Case #" << i << ": ";
    for (string s : v)
        cout << s << " ";

    cout << "\n";
        i++;
}

int main(int argc, char** argv) {
    cout << "Reading input file...\n";
    if(argc < 2)
        terminate("Usage: ./str_reversewords filename");
    
    string s{argv[1]};
    std::ifstream input{s}; // input stream       
    char dust[10];
    input.getline(dust, 10); // skip first num

    s = "";
    char c;
    // Save words both in a Vector and a List to try different reverse utilities
    vector<string> v;
    list<string> l;
    
    while (!input.eof()) {
        c = input.get();
        if (!isspace(c))
            s += c;
        else {
            // Only add the word once we reach Space of Newline
            v.push_back(s);
            l.push_back(s);
            s = "";
        }

        if (c == '\n') {
            s = "";
            reversevect(v);
            v.clear();            
            // with list, using malib2.cpp << overload
            l.reverse();
            cout << "[<list>] " << l;     
            l.clear();
        }
    }

}

