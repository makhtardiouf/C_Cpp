/**
UVA 11450 Wedding shopping max optimum expense using Dynamic Programming
partly similar to recursive backtracking.

Competetitive programming 3, P123
c++ -g -std=c++11 shopping_uva.cpp -o shopping_uva
Ref: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;

// price[g (<= 20)][model (<= 20)]
int M, C, price[25][25];

// TOP-DOWN: dp table memo
// [money (<= 200)][g (<= 20)]
int memo[210][25];

int shop(int money, int g) {
  if (money < 0)
    return std::numeric_limits<int>::min();

  // fail, return a large -ve number
  if (g == C)
    return M - money;

  /* we have bought last garment, done
    if this is skipped, top-down DP will become backtracking!!
    */
  int memg = memo[money][g];
  if (memg != -1)
    return memg; // TOP-DOWN: memoization

  // Compute un-chached values; start with a -ve number as all prices are non
  // negative
  int ans = -1;
  for (int model = 1; model <= price[g][0]; model++)
    ans = std::max(ans, shop(money - price[g][model], g + 1));

  // TOP-DOWN: memoize ans and return it
  return (memo[money][g] = ans);
}

int main() {
  int i, j, TC, score;
  scanf("%d", &TC);

  while (TC--) {
    scanf("%d %d", &M, &C);
    for (i = 0; i < C; i++) {
      // store K in price[i][0]
      scanf("%d", &price[i][0]);

      for (j = 1; j <= price[i][0]; j++)
        scanf("%d", &price[i][j]);
    }

    // TOP-DOWN: initialize DP memo table
    memset(memo, -1, sizeof memo);

    // start the top-down DP
    score = shop(M, 0);

    if (score < 0)
      printf("no solution\n");
    else
      printf("%d\n", score);
  }
  return 0;
}
