/* 
 * File:   str_reverse.cpp
 * Author: makhtar
 * Reverse a string in place
 * Created on February 7, 2016, 1:15 PM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "malib.h"
using namespace std;

string reverse2(string input) {
    char* s = strdup(input.c_str());
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

int main(int argc, char** argv) {
    string inputStr("string to reverse");
    const char* cstr = inputStr.c_str();
    stringstream ss;
    for (int i = inputStr.size(); i >= 0; i--)
        ss << cstr[i];

    cout << "With stringstream: " << ss.str();
    cout << "\nWith the reverse func: " << reverse2(strdup(cstr)) << " \n";

    if (argc > 1) {
        cout << "\nProcessing all args with spaces gives: ";

        for (int i=1; i < argc; i++)
            cout << reverse2(argv[i]) << " \n";
    }

    vector<string> v;
    v.push_back("Hello");
    v.push_back("world2");
    std::reverse(v.begin(), v.end());

    cout << "std::reverse: ";
    for (auto &s : v)
        cout << s << " ";
    cout << "\n done.\n";
    return EXIT_SUCCESS;
}

