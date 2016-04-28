/*
 * $Id: bitWise.cpp 5 2007-03-31 15:04:06Z Makhtar $
 * compile with: c++ -std=c++11 -o bitwiser bitwiser.cpp -L. -lmalib
 * -I/usr/local/include/fxt/ -lfxt
 */
#include "malib/malib.hpp"
#include <bits/bitcombcolex.h> // combinations
#include <bits/bitrotate.h>    // for bitset rotation
#include <bitset>
#include <iostream>
using namespace std;

extern void printBinary(const unsigned char val);

int main(void) {
  unsigned int a, b;

  std::bitset<4> b1("1110");
  std::bitset<4> b2("0001");
  std::cout << "b1 & b2: " << (b1 & b2) << '\n';
  std::cout << "b1 | b2: " << (b1 | b2) << '\n';
  std::cout << "b1 ^ b2: " << (b1 ^ b2) << '\n';

  cout << "Enter 2 numbers(a, b) between 0 and 255: ";
  cin >> a;
  cin >> b;

  cout << "\na in binary: \t" << printBinary(a);
  cout << endl;

  cout << "\nb in binary: \t";
  printBinary(b);
  cout << endl;

  cout << "\na bitand b = \t";
  printBinary(a bitand b);
  cout << endl;

  cout << "\na bitor b = \t";
  printBinary(a bitor b);
  cout << endl;

  cout << "\na xor b = \t";
  printBinary(a xor b);
  cout << endl;

  cout << "\ncompl a = \t";
  printBinary(compl a);
  cout << endl;

  cout << "\na & 0x5A = \t";
  printBinary(a & 0x5A);
  cout << endl;

  // using the FXT library
  cout << b1 << " (b1) rotated left: ";
  const ulong sz = b1.size();

  // ulong nb1 = bit_rotate_left(b1.to_ulong(), sz);
  // Rotation
  ulong x = b1.to_ulong();
  auto rb1 = bitset<sz>((x << sz) | (x >> (64 - sz)));
  cout << rb1 << endl;

  bitset<10> b3(1e6);
  x = last_comb(1e6);
  cout << "\nCombination for 1M (" << b3 << ") is: " << x;

  cout << endl;
  return 0;
}
