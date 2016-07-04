/**
 *
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
  printf("マス目数: ");
  cin >> n;

  int i = 0;
  while (tot < n) {
    // 乱数値 1 ~ 6
    spot = randn(6) + 1;
    if ((tot + spot) <= n) {
      tot += spot;
      printf("%d", spot);
      i++;
    }
  }
  printf("\n通り数 %d\n", i);
  return 0;
}
