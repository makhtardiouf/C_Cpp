/**
 * Determine if 2 strings are anagrams
 * a word, phrase, or name formed by rearranging the letters of another,
 * such as cinema , formed from iceman.
 * Cracking TCI P45
 * Makhtar Diouf
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isAnagram(string s1, string s2) {
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  return s1 == s2;
}

int main() {
  // Test input
  std::unordered_map<string, string> m{
      {"hhhho", "hohhh"}, {"aaaaa", "bbbba"}, {"hellno", "neohll"}};

  for (auto s : m) {
    cout << "isAnagram('" << s << ", " << m[s] << "') -> "
         << (isAnagram(s, m[s]) ? "True" : "False") << endl;
  }
  return 0;
}
