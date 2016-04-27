#include <string>
#include <cctype>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// c++ -g pangram.cpp -o pangram
// Pangrams are sentences constructed by using every letter of the alphabet at least once.

int main() {
     std::set<char> alpha;
     for(char ch = 'a'; ch <= 'z'; ch++) {
         alpha.insert(ch);
         clog<< ch << " ";
     }
     clog << endl;
     string s;
     std::set<char> alphabet;
    
     while(std::getline(std::cin, s)) {
         std::set<char> alphabet = alpha;
         char ch;
         for(int i=0; i < s.size(); i++) {
             ch = tolower(s[i]);
             clog<< ch << " ";
             if(isalpha(ch)) {
                alphabet.erase(ch);              
             }
         }
         clog << "Size alphabet: " << alphabet.size() << endl;
         if(alphabet.size() <= 0)
            cout << "pangram\n";
          else
            cout << "not pangram\n";
            
         /*for(auto it = alphabet.begin(); it != alphabet.end(); it++ )
            clog<< *it << " ";
         clog << endl;*/
     }
    return 0;
}

