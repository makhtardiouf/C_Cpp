/*
 * File:   str_reverse.cpp
 * Author: makhtar
 * Reverse a string in place
 * Created on February 7, 2016, 1:15 PM
 * $Id$
 */

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "malib.h"
using namespace std;

string reverse2(string input) {
  char *s = strdup(input.c_str());
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
  return s;
}

int main(int argc, char **argv) {
  string instr("string to reverse");
  const char *cstr = instr.c_str();
  stringstream ss;
  for (int i = instr.size(); i >= 0; i--)
    ss << cstr[i];

  cout << "With stringstream: " << ss.str();
  cout << "\nWith the reverse func: " << reverse2(strdup(cstr)) << " \n";

  if (argc > 1) {
    cout << "\nAll args with spaces: ";

    for (int i = 1; i < argc; i++)
      cout << reverse2(argv[i]);
    cout << " \n";
  }

  vector<string> v;
  v.push_back("Hello");
  v.push_back("world2");
  std::reverse(v.begin(), v.end());

  cout << "std::reverse: ";
  for (auto s : v)
    cout << s << " ";
  cout << "\n done.\n";
  return EXIT_SUCCESS;
}
