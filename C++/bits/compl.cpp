/**
Return the complement of a number
*/
#include <bitset>
#include <iostream>
using namespace std;

int solve(int n) {

  std::bitset<32> b(n);
  //b.flip();
  b = ~b;
  return b.to_ulong();
}

int main() {
  cout << solve(5);

  return 0;
}