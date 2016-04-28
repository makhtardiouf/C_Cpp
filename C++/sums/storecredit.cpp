/*
 * $Id$
 * Author: makhtar
 * https://code.google.com/codejam/contest/351101/dashboard#s=p0
 * Created on February 12, 2016, 3:32 PM
 * ONLY 2 items' prices should be == to the Total credit
 * This is a "maximum sum" problem on subsets
 */

#include "malib.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

struct _case {
  int credit;
  int numItems;
  vector<int> prices;
};

void SelectProducts(string filename);

bool getSelection(_case c);

int main(int argc, char **argv) {
  if (argc < 2)
    terminate("Usage: ./storecredit filename");

  string s{argv[1]};
  SelectProducts(s);
  return EXIT_SUCCESS;
}

void SelectProducts(string filename) {
  std::ifstream input{filename}; // input stream
  int n;
  input >> n; // first num = N test cases
  clog << n << " test cases\n";

  _case acase;
  int item;

  while (!input.eof()) {
    input >> acase.credit;
    input >> acase.numItems;
    clog << "Credit: \t" << acase.credit << "\nItems [" << acase.numItems
         << "] :\t";

    for (int i = 0; i < acase.numItems; i++) {
      input >> item;
      acase.prices.push_back(item);
      clog << item << " ";
    }

// Dont's sort coz the indexes on the initial vect are needed, 
// @todo: do a binary search or lower/upper_bound queries

    // std::sort(acase.prices.begin(), acase.prices.end(), std::less<int>());
    bool gotit = getSelection(acase);
    if (gotit == false) {
      ;
      //    getSelection(acase);
    }
  }
}

// Naive complete search
bool getSelection(_case acase) {
  list<int> selected;
  bool gotit = false;
  int a, b = 0;
  int i, j = 0;
  for (; i < acase.numItems; i++) {
    a = acase.prices[i];

    for (j = i + 1; j < acase.numItems; j++) {
      b = acase.prices[j];
      if ((a + b) == acase.credit) {
        selected.push_back(a);
        selected.push_back(b);
        gotit = true;
        break; // only two solutions
      }
      if (gotit)
        break;
    }
  }

  if (gotit) {
    clog << "\nMatches: \t";
    //  cout << "Case #" << i << ": "; // to be redirected to the output file
    for (list<int>::iterator it = selected.begin(); 
	    it != selected.end(); it++) {
      clog << *it << " ";
      //  cout << i << " " << j; // only indexes should be in the output file
    }
  }

  clog << "\n\n";
  //selected.clear();
  //acase.prices.clear();
  return gotit;
}
