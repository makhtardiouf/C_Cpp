/**
 * Dice is at n steps away from the goal, print the sequence to proceed
 * Makhtar Diouf
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int randn(int n) { return rand() % n; }

int main() {
  srand(time(0));
  int n = 0, tot = 0, spot = 0;
  printf("Steps remaining: ");
  cin >> n;

  int i = 0;
  while (tot < n) {
    // Random value 1 ~ 6
    spot = randn(6) + 1;  //std::min(n, 6);
    if ((tot + spot) <= n) {
      tot += spot;
      printf("%d", spot);
      i++;
    }
  }
  printf("\nNumber of steps %d\n", i);
  return 0;
}
