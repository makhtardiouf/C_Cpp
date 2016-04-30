/* Hanoi
 c++ -g -std=c++11 hanoi.cpp  -o hanoi

*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Hanoi {
  vector<int> discPos;
  vector< stack<int> >  rods;

public:
Hanoi(){}

  Hanoi(vector<int> &dp, vector< stack<int> >  &r) {
    discPos = dp;
    rods = r;
  }

~Hanoi() {
//delete discPos;
//for(auto x: rods)
  //   delete(x);  
}

  int solve(int n) {
    if (n >= discPos.size())
      return 0;
    
    int val = 0;
    int pos = discPos[n];
    if (pos != 0) {
      static int tmp = getRodTmp(0, discPos[0]);
      int moves = n - 1;
      val += move(moves, 0, tmp);
      val += move(rods[pos].size(), pos, 0);
      val += move(moves, tmp, 0);
    }
    val += solve(n + 1);
    return val;
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

  vector< stack<int> >  rods(n); //,stack<int>(n));
  vector<int> discPos(n + 1);

  discPos[0] = -1;
  int val = 0;
  for (int i = 1; i <= n; i++) {
    cin >> val;
    val -= 1;
    rods[val] = stack<int>();
    rods[val].push(i);
    discPos[i] = val;
  }

  auto h = Hanoi(discPos, rods);
  printf("%d\n", h.solve(1));
  return 0;
}