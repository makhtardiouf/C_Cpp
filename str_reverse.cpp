/* 
 * File:   str_reverse.cpp
 * Author: makhtar
 * Reverse a string in place
 * Created on February 7, 2016, 1:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    cout << "Input the string to reverse: ";
    string in;
    // todo: figure out how to escape spaces from the cmd line
    cin >> in;
    const char* cstr = in.c_str();

    for(int i = in.size(); i >=0 ; i--)
        cout << cstr[i];   
    
    cout << "\n done.\n";
    return 0;
}

