/* Another n-Queen Chess Problem, solved with backtracking
 * UVA 11195, ICPC
 * will be TLE, needs optimization with bitmasks
 * g++ -lm -lcrypt -O2 -pipe 01_queens_uva11195.cpp
 * Or -Og to enable optimizations that do not interfere with debugging
 */

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// n =14, 2^n -1 = 27 diagnonals (left, right)
bitset<30> rows, ld, rd;
char board[16][16];
int ans = 0;

int backtrack(int c, int n) {
  if (c == n) {
    ans++;
    return ans;
  }

  for (int r = 0; r < n; r++) {
    // checks all possible rows

    if ((board[r][c] != '*') && !rows[r] && !ld[r - c + n - 1] && !rd[r + c]) {
      rows[r] = ld[r - c + n - 1] = rd[r + c] = true;

      // flag off
      ans += backtrack(c + 1, n);
      // restore
      rows[r] = ld[r - c + n - 1] = rd[r + c] = false;
    }
  }
}

int main() {
  int nCases, n = 0;

  while (cin >> n) {
    if (n == 0)
      return 0;

    // char bch vector< vector<int> >(n, n);
    char ch;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> ch;
        board[i][j] = ch;
        bch[i][j] = ch;
        clog << ch;
      }
      clog << endl;
    }
    ans = 0;
    cout << "Case " << nCases + 1 << ": " << backtrack(0, n) << endl;
    nCases++;
  }
  return 0;
}
