/**
 * Determine shortest vector who's sum's 2^[of each element] equals that of the input vector
 * Makhtar Diouf - RkT 
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll binian2(vector<int> &A) {
  ll result = 0;
  for (auto x : A) {
    result += powl(2, x);
  }
  return result;
}

int solution(vector<int> &A) {
  // lambda version of binian2()
  auto binian = [](vector<int> &v) -> ll {
    ll result = 0;
    for (auto x : v) {
      result += powl(2, x);
    }
    return result;
  };

  ll binA = binian(A);
  clog << "\nbinian A: " << binA << endl;
  vector<int> b;

  // Determine highest divisible number close to binian of A
  ll tmp = 0;
  int hit = 0, i = 0;
  for (; tmp <= binA; i++) {
    tmp = pow(2, i);
  }
  hit = i - 2;
  b.push_back(hit);
  clog << "\nhit: " << hit << " Tmp: " << tmp << endl;

  int sz = A.size();
  ll binB = binian(b);

  while ((hit > 0) && (binB != binA) && (b.size() <= sz)) {
    hit--;
    printf("hit: %d binian B: %ld\n", hit, binB);

    b.push_back(hit);
    tmp = powl(2, hit);
    binB += tmp;
    // Backtrack
    if (binB > binA) {
      b.pop_back();
      binB -= tmp;
    }
  }
  // Should assert here that binB == binA;
  
  printf("hit: %d  binian B: %ld\n", hit, binB);
  return b.size();
}

int main() {
  vector<int> v{10, 0, 1, 10, 20, 0, 40, 3, 6, 10}; 
  // {1, 0, 2, 0, 0, 2};
  // Result = 3, coz  B = {3, 2, 0};

  printf("Shortest binian vector equal to %ld: %d\n", binian2(v),
         solution(v));

 // cout << "largest pow(2, 100000): " << pow(2, 100000) << endl;
  return 0;
}
