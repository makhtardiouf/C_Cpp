/*
 * Makhtar
 * ONLY 2 p' elems should be == to the Total n
 * This is a "maxValimum sum" problem on subsets
 */
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

struct _case {
  long n;
  int m;
  vector<long> elems;
};

long binSearch(vector<long> s, long key, int low, int high) {

  int mid = 0; // idx

  // key not found
  if (low > high)
    return -1;

  mid = (low + high) / 2;

  if (s[mid] == key)
    return mid;
  else if (s[mid] > key)
    return (binSearch(s, key, low, mid - 1));

  return (binSearch(s, key, mid + 1, high));
}

bool solve(_case &c);
bool debugOn = true;

int main(int argc, char **argv) {
  _case acase;
  // Sum to find
  cin >> acase.n;
  // Number of elems
  cin >> acase.m;

  long item;
  for (int nElems = 1; nElems <= acase.n; nElems++) {

    for (long i = 0; i < acase.m; i++) {
      cin >> item;
      acase.elems.push_back(item);
      if (debugOn)
        clog << item << " ";
    }
  }
  bool exist = solve(acase);
  if (exist)
    cout << 1 << endl;
  else
    cout << 0 << endl;

  return 0;
}

bool solve(_case &acase) {

  // long a = 0, b = 0;
  int i, j = 0;
  auto p = acase.elems;

  // Binary search works when p are sorted
  /*  std::sort(p.begin(), p.end());
    for (i = 0; i < acase.m; i++) {
      a = p[i];
      if (a > acase.n)
        continue;*/

  for (long i = 0; i < acase.m; i++) {
    for (long j = i + 1; j < acase.m; j++) {
      if (p[i] + p[j] == acase.n)
        return true;
    }
  }

  return false;
  // j = binSearch(p, acase.n - a, i, acase.m - 1);
  // b = p[j];
  /*    for (j = i + 1; j < acase.m; j++) {
   auto it = std::find(acase.elems.begin() + j, acase.elems.end(),
                         acase.n - a);
     b = *it;

   if (debugOn)
     clog << "p: " << a << " " << b << endl;
   // Not present in the rest of the sequence
     if ((a + b) != acase.n)
       break;
     else
     */
}
