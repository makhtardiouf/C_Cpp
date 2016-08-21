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
  clog << "\nInput Text:\n" << parag << "sz: " << parag.size() << endl;

  cin >> numWords;

  unordered_map<string, int> m(words.size());
  while (numWords-- > 0) {
    cin >> s;
    words.push_back(s);
    fprintf(stderr, "W: %s, ", s.c_str());
  }

  long x = 0, y = 0;
  long segLen = 200000;
  bool allWfound = false;
  vector<int> segs;

  s = "";

  for (size_t i = 0; i < parag.size(); i++) {
    if (isalpha(parag[i]))
      s += tolower(parag[i]); // !watch out
    else {
      for (auto w : words) {
        long pos = s.find(w);
        fprintf(stderr, "\nChecking %s in %s, ret:%ld\n", w.c_str(), s.c_str(),
                pos);

        if (w == s) {
          m.insert({w, m[w]++});
          allWfound = true;

          for (auto tgt : m) {
            if (tgt.second == 0) {
              allWfound = false;
              break;
            }
          }

          x++;
          y = i - s.size();
          fprintf(stderr, "%s found @ %ld\n", w.c_str(), y);
          // new segment completed
          if (allWfound)
            segLen = std::min(segLen, y - x);
          if (segLen < 1)
            segLen = 0;
          break;
        }
      }
      s = "";
    }
  }

  clog << "x, y, minSegLen:" << x << " " << y << " " << segLen << endl;

  if (!allWfound) {
    cout << "NO SUBSEGMENT FOUND";
  } else {
    for (long i = x /* y -segLen*/; i <= y; i++)
      cout << parag[i];

    fprintf(stderr, "\nm.size:%d, segLen: %ld\n", m.size(), segLen);
    for (auto el : m)
      clog << el.first << " " << el.second << endl;
  }
  cout << endl;
  return 0;
}
