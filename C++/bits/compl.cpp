/**
Return the complement of a number
*/
#include <bitset>
#include <iostream>
using namespace std;

int solve(int n) {

  std::bitset<64> b(n);
  //b.flip();
  b = ~b;
  clog << endl << b.to_string() << endl;
  return b.to_ulong();
}

int main() {
    // Should be 4 
  cout << solve(5);

  return 0;
}