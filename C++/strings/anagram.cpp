/**
 * Determine if 2 strings are anagrams:
 * a string formed by rearranging the letters of another,
 * such as cinema and iceman.
 * Cracking TCI P45
 * Makhtar Diouf
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s1, string s2) {
  if (s1.size() != s2.size())
    return false;
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return s1 == s2;
}

int main() {
  // Test input
  std::unordered_map<string, string> m{
      {"hhhho", "hohhhw"}, {"cinema", "iceman"}, {"wellno", "neowll"}};

  for (auto s : m) {
    cout << "isAnagram('" << s.first << ", " << s.second << "') -> "
         << (isAnagram(s.first, s.second) ? "True" : "False") << endl;
  }
  return 0;
}
