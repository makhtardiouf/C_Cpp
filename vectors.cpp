/* 
 * File:   vectors.cpp
 * Author: makhtar
 * $Id$
 * Created on February 8, 2016, 8:53 PM
 */
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
  
int main (int argc, char** argv)
{
  vector<int> v;
  u_int8_t i=0;
  for(; i < 10; i++)
    v.push_back (rand());
  
  v.push_back (2);
  v.push_back (2.0);  // test with double
  
  // Std lib sort algo with comparison function
  std::sort(v.begin (), v.end (), std::less<int>());
  
  // Will remove one of the '2'
  std::unique(v.begin(), v.end(), std::equal_to<int>());
            
  // Gotta use int here instead of u_int8_t otherwise it prints garbage
  for(int x : v)
    cout << x << " \n";
  
  cout << "\nReversing:\n";
  std::reverse(v.begin(), v.end ());
  for(int x : v)
    cout << "\n\t" << x ;
  
  cout << "\nLast element of v: " << v[v.size ()-1] << "\n";
  
  return EXIT_SUCCESS;
}

