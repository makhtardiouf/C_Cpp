/**
 * Makhtar Diouf
 * Google Japan University Graduate 20160301 Tests
 *
 * Compile: g++ -g -Wall -std=c++11 task3.cpp -o task3
 * Run: ./task3 < task3_small_sample.input.txt
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define Button1 ABC
#define Button2 DEF
#define Button3 GHI
#define Button4 JKL
#define Button5 MNO
#define Button6 PQRS
#define Button7 TUV
#define Button8 WXYZ


string
solve (string line)
{
  vector<string> v;
  clog << "sub: ";

  for (int i = 0, j = 0; i <= line.length () - 3; j = j + SZ, i++)
    {
    
    }
 
  cout << small << " " << slarge;
  return " ";

}

int
main (int argc, char* argv[])
{
  int C = 0; // num of test cases
  cin >> C;
  clog << C << " test cases\n";
  cin.get (); // \n

  vector<char> bts[8]; // buttons

      for(int i = 0, char ch = 'A'; ch <= 'Z'; ch++, i++) {
            bts[i].push_back (ch);
    }
  
  string line;

  for (int k = 0; k < C; ++k)
    {
      std::getline (cin, line);
      clog << "Line = " << line << "\n";

      cout << "Case #" << k + 1 << ": ";
      solve (line);
      cout << "\n";
    }

  return 0;
}
