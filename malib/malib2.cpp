/*
* $Id: malib2.cpp 9 2007-07-11 08:22:53Z Makhtar $
* Implementation of c++ routines
*/
#include "malib.hpp"
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;
// To speed up iostream, use:
// ios_base::sync_with_stdio(false);

// template<typename T>
std::ostream &operator<<(std::ostream &ostr,
                         const std::list<std::string> &list) {
  for (auto &i : list) {
    ostr << " " << i;
  }
  ostr << "\n";
  return ostr;
}

ull rangeMaxSum(std::vector<ull> &a, ull M) {
  ull ans = numeric_limits<ull>::min();

  ull mn = 0, s = 0;
  for (ull i = 0; i < a.size(); ++i) {
    s += a[i];
    if (a[i] <= 2)
      mn = s % M;
    else {
      ans = max(ans, (s - mn) % M);
      mn = min(mn, s) % M;
    }
  }

  if (ans == numeric_limits<ull>::min() % M)
    return 0;
  else
    return ans;
}

// Maximum sum of subsets of an array/vector
int maxSum(vvi &v) {
 // typedef long long T;
 typedef int T;
  T n = v.size();

  // lowest possible value
  T maxSubRect = -1; //numeric_limits<T>::min();

  for (T l = 0; l < n; l++)
    for (T r = l; r < n; r++) {
      T subRect = 0;

      for (T row = 0; row < n; row++) {
        // Max 1D Range Sum on columns of this row i
        if (l > 0)
          subRect += v[row][r] - v[row][l - 1];
        else
          subRect += v[row][r];
        // Kadane’s algorithm on rows
        if (subRect < 0)
          subRect = 0;

        // greedy, restart if running sum < 0
        maxSubRect = std::max(maxSubRect, subRect);
      }
    }
  return maxSubRect;
}

/* Get the execee's name and arguments then fork it */
int spawn(const char *cmd[]) {
  std::string command(cmd[0]);

  for (int i = 1; cmd[i] != NULL; ++i) {
    command.append(" -");
    command.append(cmd[i]);
  }

  FILE *process;
  if ((process = popen(command.c_str(), "w")) != NULL) {
    pclose(process);
    return EXIT_SUCCESS;
  }

  perror(cmd[0]);
  return EXIT_FAILURE;
}
