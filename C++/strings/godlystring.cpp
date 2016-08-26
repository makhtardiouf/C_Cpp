
/*
Makhtar Diouf

A "godly" string is a string A such that for all distinct characters in A, each character occurs the same number of times in A.

For example,aabb is a godly string because the frequency of both characters a and b is 2,
whereas aabbc is not a godly string because the frequency of characters a,b,and c is not same.

We can remove characters from the string to make it godly.
Can the given string be converted to godly string with one or less removal ?
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	string s;
	cin >> s;

	map<char, int> m;
	char ch;
	int maxNchs = 0;  // goes up
	int minNchs = s.size();  // threshold goes down

	int chWithMax = 0, chWithMin = 0;

	for (int i = 0; i < s.size(); i++) {
		ch = s[i];
		m.insert({ ch, m[ch]++ });
		maxNchs = std::max(maxNchs, m[ch]);
		minNchs = std::min(minNchs, m[ch]);

		fprintf(stderr, "ch %c, m[ch] %d \n", ch, m[ch]);
		fprintf(stderr, "min %d, max %d \n", minNchs, maxNchs);
	}

	for (auto el : m) {
		ch = el.first;
		if (m[ch] > minNchs)
			chWithMax++;
		else if (m[ch] == minNchs)
			chWithMin++;
	}

	int numOfRemovals = 0;

	if (maxNchs == minNchs)
		cout << "YES\n";
	else {

		// recount
		maxNchs = 0, minNchs = s.size();

		if (chWithMin > chWithMax) {
			// remove 1 ch in the group that has more
			fprintf(stderr, "Rm chWithMax: %d (min: %d) \n", chWithMax, chWithMin);

			for (auto &el : m) {
				if (el.second > minNchs) {
					el.second--;
					numOfRemovals++;
				}

				maxNchs = std::max(maxNchs, el.second);
				minNchs = std::min(minNchs, el.second);
			}
		}
		else {
			// remove 1 ch in the group that has less
			fprintf(stderr, "Rm chWithMin: %d (max: %d) \n", chWithMin, chWithMax);

			for (auto &el : m) {
				if (el.second <= minNchs) {
					el.second--;
					numOfRemovals++;
				}

				maxNchs = std::max(maxNchs, el.second);
				minNchs = std::min(minNchs, el.second);
			}
		}
	}

	fprintf(stderr, "min %d, max %d, numOfRm: %d \n", minNchs, maxNchs, numOfRemovals);

	if ((maxNchs == minNchs) && (numOfRemovals <= 1))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
