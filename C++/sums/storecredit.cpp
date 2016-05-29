/*
 * $Id$
 * Author: makhtar
 * https://code.google.com/codejam/contest/351101/dashboard#s=p0
 * Created on February 12, 2016, 3:32 PM
 * ONLY 2 items' prices should be == to the Total credit
 * This is a "maximum sum" problem on subsets

 make storecredit
 build/storecredit A-small-storecredit.in > storecredit.out
 */
#include "malib/malib.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

struct _case {
  long credit;
  int numItems;
  vector<long> prices;
};

bool solve(_case &c);
bool debugOn = true;

int main(int argc, char **argv) {
  if (argc < 2)
    terminate("Usage: ./storecredit filename");

  string s{argv[1]};
  std::ifstream input{s};
  int n;
  input >> n;
  if (debugOn)
    clog << n << " test cases\n";

  long item;
  for (int nCase = 1; nCase <= n; nCase++) {
    _case acase;
    input >> acase.credit;
    input >> acase.numItems;
    if (debugOn)
      clog << "Credit: \t" << acase.credit << "\nItems [" << acase.numItems
           << "] :\t";

    for (long i = 0; i < acase.numItems; i++) {
      input >> item;
      acase.prices.push_back(item);
      if (debugOn)
        clog << item << " ";
    }

    printf("Case #%d: ", nCase);
    solve(acase);
  }
  return EXIT_SUCCESS;
}

bool solve(_case &acase) {

  long a = 0, b = 0;
  int i, j = 0, k = 0;
  auto p = acase.prices;

  // Binary search works when items are sorted
  // std::sort(p.begin(), p.end());
  // j = binSearch<long>(p, acase.credit - a, 0, acase.numItems - 1);

  for (i = 0; i < acase.numItems; i++) {
    a = p[i];
    if (a > acase.credit)
      continue;

    // Naive O(n^2) runtime works for small input
    for (j = i + 1; j < acase.numItems; j++) {
      auto it = std::find(acase.prices.begin() + i + 1, acase.prices.end(),
                          acase.credit - a);
      b = *it;
      if (debugOn)
        fprintf(stderr, "\ni j, a, b: %d %d, %ld %ld\n", i, j, a, b);

      // Not present in the rest of the sequence
      if ((a + b) != acase.credit)
        break; // continue;

      // Index of selected prices in the initial sequence, start with 1
      k = it - acase.prices.begin() + 1;
      cout << i + 1 << " " << k << endl;
      return true;
    }
  }
  return false;
}
