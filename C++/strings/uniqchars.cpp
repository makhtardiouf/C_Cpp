/**
 * Determine if a string has all unique characters
 * Cracking TCI P45
 * Makhtar Diouf
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool uniqCharsOnly(string s) {
  char ch = s[0];
  for (int i = 1; i < s.size(); i++)
    if (s[i] != ch)
      return false;

  return true;
}

int main() {
  vector<string> sv{"hhhh", "hellno", "aaaaa", "bbbba"};

  for (auto s : sv) {
    cout << "uniqCharsOnly('" << s << "') -> " << (uniqCharsOnly(s)? "True": "False") << endl;
  }
  return 0;
}
