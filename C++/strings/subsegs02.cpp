/**
 Given a paragraph of text, write a program to find the first shortest
 sub-segment that contains each of the given k words at least once.
 A segment is said to be shorter than other if it contains less number of words.

[Uncomplete Version!!]
 $Id$
 Makhtar Diouf
*/

#include <cstring>
#include <cstdio>
#include <iostream>
//#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct _seg {
	long x = 0;
	long y = 0;
	int numWords = 0;
};

int countNumWords(string &parag, _seg &seg) {
	seg.numWords = 0;
	long i = seg.x;
	for (; i < seg.y; i++) {
		if (isspace(parag[i]))
			seg.numWords++;
	}
	fprintf(stderr, "Seg [%ld:%ld], numW: %d\n", seg.x, seg.y, seg.numWords);
	return seg.numWords;
}

int main() {
	int numWords = 0;
	string parag = "This is a test. This is a programming test. This is a programming test in any language.";
	string s = "";
	// Forced by VC++
	char cstr[50];

	//getline(std::cin, parag);
	fprintf(stderr, "\nInput Text: %s sz: %d\n", parag.c_str(), parag.size());

	cin >> numWords;
	vector<string> words;
	fprintf(stderr, "\n");

	while (numWords-- > 0) {
		std::cin >> cstr; // s;
		s = cstr;
		words.push_back(s);
		fprintf(stderr, "W: %s, ", s.c_str());
	}

	int segLen = 200000;
	unordered_map<string, int> m(words.size());
	s = "";
	_seg seg;
	vector<_seg> segments;
	bool allWfound = false;

	for (size_t i = 0; i < parag.size(); i++) {
		if (isalpha(parag[i]))
			s += tolower(parag[i]);
		else {

			for (auto w : words) {
				if (w != s)
					continue;

				if (seg.numWords == 0)
					seg.x = i - s.size(); // beginning of 1st word

				seg.y = i;                // end of last word				

				fprintf(stderr, "%s found @ %ld\n", w.c_str(), seg.y);

				m.insert({ w, m[w]++ });
				seg.numWords++;
				if (m[w] > 1) {
					seg.numWords--;
					seg.x += w.size();
				}

				// Completed segment
				if ((seg.numWords == words.size())) {
					allWfound = true;
					for (auto tgt : m) {
						//	fprintf(stderr, "Tgt: %s %d \n", tgt.first.c_str(), tgt.second);
						if (tgt.second == 0) {
							allWfound = false;
							break;
						}
					}
					if (allWfound) {
						segLen = std::min(segLen, seg.numWords);

						// Better word count
						countNumWords(parag, seg);
						segments.push_back(seg);

						// For next segment
						seg.numWords = 0;
						//	seg.x = 0;
						//	seg.y = 0;
						allWfound = false;
						m.clear();
					}
				}
				break;
			}
			s = "";
		}
	}

	if (segments.size() == 0) {
		cout << "NO SUBSEGMENT FOUND\n";
	}
	else {

		struct {
			// Earliest shortest segment
			bool operator()(_seg a, _seg b) { return (a.numWords < b.numWords); }
		} shortSeg;

		std::sort(segments.begin(), segments.end(), shortSeg);

		for (auto s : segments) {
			for (long i = s.x; i <= s.y; i++) {
				char c = parag[i];
				if (isalpha(c) || isspace(c))
					cout << c;
			}
			cout << endl;
		}

		int stop;
		std::cin >> stop;
	}
	return 0;
}
