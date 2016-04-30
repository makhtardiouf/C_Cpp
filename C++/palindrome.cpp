/*
 * Author: Makhtar Diouf
 * Check if a string is a palindrome, e.g anna, petep, reversing it gives the
 * same words
 * c++ -g -std=c++11 -Wall palindrome.cpp -o palindrome
 * February 27, 2016, 2:22 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
  for (u_int32_t i = 0, j = s.length() - 1; i < s.length(); i++, j--) {

    if (s[i] != s[j])
      return false;
    cout << "\nchar '" << s[i] << "' and '" << s[j] << "' match";
  }
  return true;
}

int main(int argc, char **argv) {
  string s = "";
  // Prevent buffer overflow by limit the number of chars to read
  cin.width(20);

  while (s != "q") {
    cout << "\nInput a palindrome string or q to quit: ";
    cin >> s;
    if (isPalindrome(s))
      cout << "\nThus '" << s << "' is a palindrome !\n";
    else
      cout << "\nNope that is not a palindrome \n";
  }

  return 0;
}
