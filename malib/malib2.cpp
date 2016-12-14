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

// Binary search
template <typename T> long binSearch(vector<T> s, T key, int low, int high) {

  int mid = 0; // idx

  // key not found
  if (low > high)
    return -1;

  mid = (low + high) / 2;

  if (s[mid] == key)
    return mid;
  else if (s[mid] > key)
    return (binSearch(s, key, low, mid - 1));

  return (binSearch(s, key, mid + 1, high));
}

// template<typename T>
std::ostream &operator<<(std::ostream &ostr,
                         const std::list<std::string> &list) {
  for (auto &i : list) {
    ostr << " " << i;
  }
  ostr << "\n";
  return ostr;
}

// Maximum sum of ranges of size M
ull rangeMaxSum(std::vector<ull> &a, ull M) {
  // -INF
  ull ans = std::numeric_limits<ull>::min();

  ull mn = 0, sum = 0;
  for (ull i = 0; i < a.size(); ++i) {
    sum += a[i];
    // Only 2 items
    if (a[i] <= 2)
      mn = sum % M;
    else {
      ans = std::max(ans, (sum - mn) % M);
      mn = std::min(mn, sum) % M;
    }
  }

  if (ans == std::numeric_limits<ull>::min() % M)
    return 0;
  else
    return ans;
}

// Maximum sum of 1D vector
int maxSum(std::vector<int> &v) {
  int msum = std::numeric_limits<int>::min();
  int tmp = 0;

  for (int i = 0; i < v.size(); i++) {
    tmp += v[i];
    // Reset if negatif
    tmp = std::max(0, tmp);
    msum = std::max(msum, tmp);
  }

  return msum;
}

// Maximum sum of subsets of a 2D vector
template <typename T> T maxSum2D(std::vector<std::vector<T>> &v) {
  T n = v.size();

  // lowest possible value
  T maxSubRect = std::numeric_limits<T>::min();

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
