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
#include <map>
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
  int segLen = 200000;
  bool allWfound = false;
  unordered_map<long, long> segments;
  numWords = 0;
  s = "";

  for (size_t i = 0; i < parag.size(); i++) {
    if (isalpha(parag[i]))
      s += tolower(parag[i]);
    else {
      for (auto w : words) {

        if (w == s) {
          if (numWords == 0)
            x = i - s.size();
          numWords++;
          m.insert({w, m[w]++});
          
          allWfound = true;
          for (auto tgt : m) {
            if (tgt.second == 0) {
              allWfound = false;
              break;
            }
          }
          y = i;
          fprintf(stderr, "%s found @ %ld\n", w.c_str(), y);

          // new segment completed
          if ((numWords >= words.size()) && allWfound) {
            segLen = std::min(segLen, numWords);
            segments.insert({x, y});
            // For next segment
            numWords = 0;
            m.clear();
          }
          break;
        }
      }
      s = "";
    }
  }

  clog << "x, y, minSegLen:" << x << " " << y << " " << segLen << " words" << endl;

  if (!allWfound) {
    cout << "NO SUBSEGMENT FOUND\n";
  } else {
    for (auto s : segments) {
      fprintf(stderr, "\n\n------Results\nSegment [%ld:%ld] :\n", s.first,
              s.second);

      for (long i = s.first; i <= s.second; i++) {
        char c = parag[i];
        if (isalpha(c) || isspace(c))
          cout << c;
      }
      cout << endl;
    }
  }
  return 0;
}
