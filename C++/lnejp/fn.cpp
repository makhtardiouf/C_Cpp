/**
 *
 * Makhtar Diouf
*/
#include <iostream>

long long fn(long long n) {

  if ((n == 0) || (n == 1))
    return n;

  // return fn(n - 1) + fn(n - 2);
  long long t1 = 0, t2 = 1;
  long long tot = t1 + t2;

  while (tot < n) {
    t1 = t2;
    t2 = tot;
    tot = t1 + t2;
  }
  return tot;
}

int main() {
  std::cout << "fn(8181) = " << fn(8181) << std::endl;
  return 0;
}
