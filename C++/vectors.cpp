/* 
 * Trivial operations on vector
 * Author: makhtar
 * $Id$
 * Created on February 8, 2016, 8:53 PM
 * g++ -g -std=c++14 vectors.cpp -o vectors
 */
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printVect(vector<auto> v) {
  for(auto x : v)
    cout << "\n\t" << x ;
}

int main (int argc, char** argv)
{
  vector<int> v;
  v.assign(4, 15);

  for(uint8_t i = 0; i < 5; i++)
    v.push_back (i);
  v.push_back (2);
  v.push_back (2.0);  // test with double
  
  // Std lib sort algo with comparison function
  std::sort(v.begin (), v.end (), std::less<int>());
  cout << "Sort vector of size: "<< v.size() <<" \n";
  printVect(v);

  // remove one of the '2'
  cout << "\nUnique: \n";
  std::unique(v.begin(), v.end(), std::equal_to<int>());
  printVect(v);
  
  cout << "\nReversing:\n";
  std::reverse(v.begin(), v.end ());
  printVect(v);
  cout << "\nLast element of v: " << v[v.size ()-1] << "\n";

  std::vector<char> txt;
  txt.assign(5, 'a');
  printVect(txt);

  return EXIT_SUCCESS;
}

