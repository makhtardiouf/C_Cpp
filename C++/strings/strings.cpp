// $Id: strings.cpp 5 2007-03-31 15:04:06Z Makhtar $

#include "malib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(void) {
  string s1, s2;
  string s3 = "\nHello, yow!\nGuess who's back";
  s2 = "Today is the day";
  s1 = s2 + " " + s3;
  s1 += " hey "; // appending to a string
  cout << s1 + s2 + "!" << endl << endl;

  // Manipulating c-style string with pointers
  // p points to s3[0]
  char *p = const_cast<char *>(s3.c_str()); // or use const char* p
  for (; *p != '\0'; p++) {
    // avoid buffering
    clog << *p;
    usleep(400000);
  }
  cout << endl;

  cout << "Enter a phrase: ";
  std::getline(cin, s1);
  cout << "got: " << s1;

  cout << "\nIndicate a file to read: ";
  cin >> s1;
  ifstream fp(s1);
  while (fp) {
    std::getline(fp, s1);
    typewrite(s1.c_str());
    cout << "\n";
  }
  fp.close(); // implicit

  return 0;
}
