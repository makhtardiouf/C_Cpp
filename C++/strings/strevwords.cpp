/**
 * $Id$
 * Author: Makhtar Diouf
 * Compilation g++ -std=c++11 -g -Wall strevwords.cpp malib2.cpp -o
 * strevwords 
 * Google codejam:  run with ./strevwords B-small-streverse.in
 * https://code.google.com/codejam/contest/351101/dashboard#s=p1
 */
#include "../malib/malib.hpp"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

void reverseVect(vector<string> v) {
  static int i = 1;
  std::reverse(v.begin(), v.end());
  cout << "Case #" << i << ": ";
  for (string s : v)
    cout << s << " ";

  cout << "\n";
  i++;
}

int main(int argc, char **argv) {
  clog << "Reading input file...\n";
  if (argc < 2)
    terminate("Usage: ./strevwords filename");

  string s{argv[1]};
  std::ifstream input{s}; // input stream
  char dust[10];
  input.getline(dust, 10); // skip first num

  // Save words both in a Vector and a List to try different reverse utilities
  vector<string> v;
  list<string> l;
  s = "";
  char c;

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
      reverseVect(v);
      v.clear();
      
      l.reverse();
      cout << "[<list>] ";
      for(auto it: l)
        cout << it << " ";
      cout << endl;
      l.clear();
    }
  }
  return 0;
}
