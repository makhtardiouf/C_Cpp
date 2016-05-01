/* Hanoi
 c++ -g -std=c++11 hanoi.cpp  -o hanoi

*/
#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Hanoi {
  vector<int> discPos;
  vector<stack<int>> rods;

public:
  Hanoi() {}

  Hanoi(vector<int> dp, vector<stack<int>> r) {
    discPos = dp;
    rods = r;
  }

  ~Hanoi() {
    cerr << "\nDestructor\n";
    // delete discPos;
    // for(auto x: rods)
    //   delete(x);
  }

  int solve(int n) {
    if (n >= discPos.size())
      return 0;

    int val = 0;
    int pos = discPos[n];
    if (pos != 0) {
      int tmp = getRodTmp(0, discPos[0]);
      int moves = n - 1;
      val += move(moves, 0, tmp);
      val += move(rods[pos].size(), pos, 0);
      val += move(moves, tmp, 0);
    }
    return val + solve(n + 1);
  }

  int getRodTmp(int i, int i0) {
    int val = 0;
    while (val == i || val == i0) {
      val = (val + 1) % 4;
    }
    return val;
  }

  int move(int elem, int from, int to) {
    if (elem <= 0)
      return 0;

    int val = 0;
    if (elem == 1) {
      val = rods[from].size() - 1;
      rods[from].pop();
      rods[to].push(val);
      discPos[val] = to;
      return 1;
    }

    int tmp = getRodTmp(from, to);
    val = move(elem - 1, from, tmp);
    val += move(1, from, to);
    val += move(elem - 1, tmp, to);
    return val;
  }
};

int main() {
  // num of discs
  int n = 0;
  cin >> n;

  try {
    vector<stack<int>> rods(4); //,stack<int>(n));
    vector<int> discPos(n + 1);

    discPos[0] = -1;
    int val = 0;
    // rods[0] = stack<int>();
    for (int i = 1; i <= n; i++) {
      cin >> val;
      val -= 1;
      if (!rods[val])
        rods[val] = stack<int>();
      rods[val].push(i);
      discPos[i] = val;
    }

    auto h = Hanoi(discPos, rods);
    cout << h.solve(1) << endl;
    // delete discPos;
    return 0;

  } catch (exception ex) {
    fprintf(stderr, "\nError: %s\n", ex.what());
  }
  return 0;
}