/**
 * Makhtar Diouf
 * Google Japan University Graduate 20160301 Tests
 *
 * Compile: g++ -g -Wall -std=c++11 task1.cpp -o task1
 * Run: ./task1 < task1_small_sample.input.txt
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;
#define SZ 3  // substring length

string
solve (string line)
{
  string small;
  string slarge;
  vector<string> v;
  clog << "sub: ";

  for (unsigned int i = 0, j = 0; i <= line.length () - SZ; j = j + SZ, i++)
    {
      string sub = line.substr (i, 3);
      v.push_back (sub);
      clog << sub << " ";
    }
  std::sort (v.begin (), v.end ());
  small = v[0];
  slarge = v[v.size () - 1];

  return (small + " " + slarge);
}

int
main (void)
{
  int C = 0; // num of test cases
  cin >> C;
  clog << C << " test cases\n";
  cin.get (); // \n

  string line;

  for (int k = 0; k < C; ++k)
    {
      std::getline (cin, line);
      clog << "Line = " << line << "\n";

      cout << "Case #" << k + 1 << ": " << solve (line) << "\n";
    }

  return 0;
}
