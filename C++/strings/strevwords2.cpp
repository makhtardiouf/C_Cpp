/**
 * $Id$
 * Author: Makhtar Diouf
 * Reverse and capitalize words one a time
 
 * Compilation: make strevwords2
 * e.g.  "Hello World" -> "Olleh Dlrow"
 */
#include "../malib/malib.hpp"
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

// Reverse C-style strings
char *reverse(char *s) {
  int i, j;
  int len = strlen(s);
  s[0] = tolower(s[0]);
  s[len - 1] = toupper(s[len - 1]);

  for (i = 0, j = len - 1; i < j; i++, j--) {
    std::swap(s[i], s[j]);
  }
  return s;
}

int main(int argc, char **argv) {
  char c;
  string s = "";
  vector<string> input{"Che;ck", "He?llo Wo.rld", "How_is it"};

  for (uint i = 0; i < input.size(); i++) {
    printf("%s [%d chars] -> ", input[i].c_str(), input[i].size());

    // Process each word of the initial string, one char at a time
    for (uint j = 0; j < input[i].size(); j++) {
      c = input[i][j];
      if (isalnum(c)) {
        s += c;
      } else if(isspace(c)) {
        // Hit a space, so reverse the word
        cout << reverse(strdup(s.c_str())) << " ";
        s = "";
      }
    }
    cout << reverse(strdup(s.c_str())) << " ";
    s = "";    
    cout << endl;
  }
  return 0;
}
