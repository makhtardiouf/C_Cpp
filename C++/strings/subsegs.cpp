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

int main() {
  int numWords = 0;
  string parag, s;
  vector<string> words;
  std::getline(cin, parag);
  clog << "\nInput Text:\n" << parag << "sz: " << parag.size() << endl;

  cin >> numWords;
  while (numWords-- > 0) {
    cin >> s;
    words.push_back(s);
    fprintf(stderr, "W: %s, ", s.c_str());
  }

  int segLen = 200000;
  bool allWfound = false;
  struct _seg {
    long x = 0;
    long y = 0;
    int numWords = 0;
  };

  vector<_seg> segments;

  unordered_map<string, int> m(words.size());
  s = "";
  _seg seg;

  for (size_t i = 0; i < parag.size(); i++) {
    if (isalpha(parag[i]))
      s += tolower(parag[i]);
    else {
      for (auto w : words) {
        if (w != s)
          continue;

        if (seg.numWords == 0)
          seg.x = i - s.size(); // beginning of 1st word
        seg.y = i;              // end of last word
        fprintf(stderr, "%s found @ %ld\n", w.c_str(), seg.y);

        m.insert({w, m[w]++});
        seg.numWords++;
        if (m[w] > 1)
          seg.numWords--;

        allWfound = true;
        for (auto tgt : m) {
          fprintf(stderr, "Tgt: %s %d \n", tgt.first.c_str(), tgt.second);
          if (tgt.second == 0) {
            allWfound = false;
            break;
          }
        }

        // Completed segment
        if ((seg.numWords == words.size()) && allWfound) {
          segLen = std::min(segLen, seg.numWords);
          segments.push_back(seg);

          // For next segment
          seg.numWords = 0;
          seg.x = 0;
          seg.y = 0;
          allWfound = false;
          m.clear();
        }
        break;
      }
      s = "";
    }
  }

  if (!allWfound) {
    cout << "NO SUBSEGMENT FOUND\n";
  } else {
    struct {
      bool operator()(_seg a, _seg b) { return a.numWords < b.numWords; }
    } shortSeg;

    for (auto s : segments) {
      fprintf(stderr, "\n\n------Results\nSegment [%ld:%ld], numW: %d\n", s.x,
              s.y, s.numWords);
    }
    std::sort(segments.begin(), segments.end(), shortSeg);

    for (long i = segments[0].x; i <= segments[0].y; i++) {
      char c = parag[i];
      if (isalpha(c) || isspace(c))
        cout << c;
    }
    cout << endl;
  }
  return 0;
}
