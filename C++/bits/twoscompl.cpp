/**
 Times out on large N
 c++ -std=c++11 -g -Wall -o twoscomplement  twoscomplement.cpp
 Add one to each number and count the number of bits set to 1
*/
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

unsigned int countSetBits(unsigned long x)
{
    if (x <= 0)
        return 0;
    return (x %2 == 0? 0: 1) + countSetBits (x/2);
}

int solve(int A, int B) {
  int num1Bits = 0;
  // bitset<32> one(1);
  bitset<32> a(0);

  for (int i = A; i <= B; i++) {
   // a = bitset<32>(i);
   if (i < 0) {   
     a = ~a; // one's complement
     a ^= bitset<32>(1);
    }
    
    num1Bits += a.count(); //countSetBits(a.to_ulong());
  }

  return num1Bits;
}

int main() {
  clock_t t0 = clock();
  int nCases;
  cin >> nCases;
  int A, B = 0;
    
  for (int k = 0; k < nCases; k++) {    
    cin >> A >> B;
    printf("%d\n", solve(A, B));
  }

  clock_t t1 = clock();
  fprintf(stderr, "\nRuntime = %.4f s\n", (t1 - t0) / (double)CLOCKS_PER_SEC);
  return 0;
}
