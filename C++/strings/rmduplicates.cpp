/**
 * Remove the duplicate characters in a string without using any additional
 * buffer
 * Cracking TCI P45
 * Makhtar Diouf
*/
#include <iostream>
#include <unordered_map>  // can be faster than <map>
#include <vector>

using namespace std;

string rmDuplicates(string s) {
  char ch;
  uint32_t sz = s.size();
  std::unordered_map<char, int> m(sz);

  for (uint32_t i = 0; i < sz; i++) {
    ch = s[i];
    m[ch]++;
    if (m[ch] > 1) {
      s.erase(i, 1);
      --sz;
      --i;
    }
  }
  return s;
}

int main() {
  vector<string> sv{"ehehhh", "hellno", "wuuuuuw", "bbbba"};

  for (auto s : sv) {
    cout << "rmDuplicates('" << s << "') -> " << rmDuplicates(s) << endl;
  }
  return 0;
}
