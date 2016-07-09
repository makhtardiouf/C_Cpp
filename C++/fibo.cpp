/**
 * Fibonnaci, in a different way
 * Makhtar Diouf
*/
#include <cstdio>

long long fibo(long long n) {

  if ((n == 0) || (n == 1))
    return n;

  // return fibo(n - 1) + fibo(n - 2);
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
  printf("fibo(10) = %lld\n", fibo(8181));
  return 0;
}
