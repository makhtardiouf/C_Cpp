// $Id: strings.cpp 5 2007-03-31 15:04:06Z Makhtar $
// make -f ../Makefile strings
#include "malib.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <autosprintf.h>

using gnu::autosprintf;
using namespace std;

int main(void) {
  auto t0 = clock();
  
  string s1, s2;
  string s3 = "\nHello, yow!\nGuess who's around";
  s2 = "Hope you're having a great day";
  s1 = s2 + " " + s3;
  s1 += " hey "; // append
  cout << s1 + s2 + "!\n\n" ;

  // Manipulating c-style string with pointers
  // p points to s3[0], can use const char* p
  char *p = const_cast<char *>(s3.c_str());
  for (; *p != '\0'; p++) {
    // avoid buffering
    clog << *p;
    usleep(400000);
  }
  cout << endl;

  cout << "Enter a phrase: ";
  std::getline(cin, s1);
  cout << "Got: " << s1;

  auto t1 = clock();
  cout << autosprintf ("\nAll input: %s %s.\n Runtime: %f\n", p, s1.c_str(), (t1 - t0) / (double)CLOCKS_PER_SEC);
  return 0;
}
