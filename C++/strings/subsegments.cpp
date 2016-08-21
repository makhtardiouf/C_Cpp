/**
 Given a paragraph of text, write a program to find the first shortest
 sub-segment that contains each of the given k words at least once. 
 A segment is said to be shorter than other if it contains less number of words.

[Uncomplete BUGGY Version!!]
 $Id$
 Makhtar Diouf
*/
#include "malib.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

string solve(string parag, int numWords) {
  unordered_map<string, int> m(parag.size());
  string s;
  for (int i = 0; i < parag.size(); i++) {
    if (!isspace(parag[i]))
      s += parag[i];
    else {
      m.insert({s, m[s]++});
      s = "";
    }
  }
  for (auto el : m)
    cout << el.first << ": " << el.second << endl;

  return "NO SUBSEGMENT FOUND";
}

int main() {
  int numWords = 0;
  string parag, s;
  vector<string> words;
  std::getline(cin, parag);
  clog << "\nInput Text:\n" << parag;

  cin >> numWords;

  unordered_map<string, int> m(parag.size());
  while (numWords-- > 0) {
    cin >> s;
    words.push_back(s);
  }

  for (int i = 0; i < parag.size(); i++) {
    if (!isspace(parag[i]))
      s += tolower(parag[i]);  // !watch out
    else {
      for (auto w : words) {
        if (w == s) {
          m.insert({s, m[s]++});
          break;
        }
      }
      s = "";
    }
  }

  if (m.size() != words.size()) // !nope!
    cout << "NO SUBSEGMENT FOUND";
  else {
    for (auto el : m)
      cout << el.first << " ";
  }
  cout << endl;
  return 0;
}
