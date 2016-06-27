/**
 * Count shapes: squares, rectangles or else after parsing input string
 * e.g "36 30 36 30" , "100 100 100 100" ...
 * Makhtar Diouf
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  int nSq = 0, nRect = 0, other = 0;
  int a, b, c, d = 0;
  string s;
  istringstream is;

  while (!cin.eof()) {
    // Split the input string "A B C D"
    std::getline(cin, s);
    is >> a >> b >> c >> d;
    fprintf(stderr, "Got: %d %d %d %d\n", a, b, c, d);

    if ((a <= 0) || (b <= 0) || (c <= 0) || (d <= 0))
      other++;
    else if (a == b == c == d)
      nSq++;
    else if ((a == c) && (b == d))
      nRect++;
    else
      other++;
  }

  fprintf(stderr, "Counts: ");
  cout << nSq << " " << nRect << " " << other << endl;
  return 0;
}
