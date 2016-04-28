/**
   Competitive programming library constructs:
   * Segment tree  stored like a heap array, used for
   Static Range Minimum/Maximum/Sum queries. P80
   Makhtar diouf
   $Id$
   c++ -g -Wall -std=c++11 segment_tree.cpp -o segment_tree
*/
#include "malib/malib.hpp"
#include <cmath>
using namespace std;

bool dbg = true;
enum Range { SUM = 0, MIN, MAX };

class SegmentTree {
private:
  vector<int> segTree;
  vector<int> A;

  // Range operation
  int opt = 1; //, p = 1; //, parent node
  int b, e = 0;

  bool isInited = false;
  inline int left(int p) {
    return p << 1; // = 2*p
  }
  inline int right(int p) {
    return (p << 1) + 1; // = 2*p +1
  }

public:
  SegmentTree(vector<int> &A) {
    int N = A.size();
    this->A = A;

    // required tree length: 2*2^(floor(log2(N)) + 1)
    int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    this->segTree.resize(length);
  }

  /**
     Populate the tree
     @param opt: Sum, Min, Max
     @param b: begin
     @param e: end
     * Complexity  O(n * log n)
     */
  void build(int opt, int p, int b, int e) {
    this->opt = opt;
    if (!isInited) {
      this->b = b;
      this->e = e;
      isInited = true;
    }

    // Leaf
    if (b == e) {
      if (opt == Range::SUM)
        this->segTree[p] = this->A[b]; // store value

      else
        this->segTree[p] = b; // store index

      // No subtrees from leafs
      return;
    }

    // Recursively compute the values in the Left and Right subtrees
    build(opt, left(p), b, (b + e) / 2);
    build(opt, right(p), (b + e) / 2 + 1, e);

    int lVal = this->segTree[left(p)];
    int rVal = this->segTree[right(p)];
    // if(dbg) clog << "lVal, rVal: " << lVal << ", " << rVal << endl;

    switch (opt) {
    case Range::SUM:
      this->segTree[p] = lVal + rVal;
      break;

    case Range::MAX:
      this->segTree[p] = (A[lVal] >= A[rVal]) ? lVal : rVal;
      break;

    default:
      // MIN
      this->segTree[p] = (A[lVal] <= A[rVal]) ? lVal : rVal;
    }
  }

  int rmq(int opt, int i, int j) {
    if (dbg)
      clog << "RMQ: " << i << ", " << j << ": \n";
    return query(opt, 1, i, j);
  }

private:
  /**
   *  Query part of the tree
   *  Complexity  O(log n)
   *
   */
  int query(int opt, int p, int i, int j, int b = 0, int e = 6) {
    if (dbg)
      clog << "b, e " << b << ", " << e << endl;
    // Early sanity checks
    if (i > e || j < b)
      return -1;
    // inside query interval, return root node
    else if (b >= i && e <= j)
      return this->segTree[p]; //!!! issue point here

    // minimum position on the Left/Right
    int p1 = query(opt, left(p), i, j, b, (b + e) / 2);

    int p2 = query(opt, right(p), i, j, (b + e) / 2 + 1, e);

    if (dbg)
      clog << "p1, p2: " << p1 << ", " << p2 << endl;

    // position where the overall minimum is
    if (p1 == -1)
      return p2; // outside query
    if (p2 == -1)
      return p1;

    if (opt == Range::SUM)
      return p1 + p2;
    else if (opt == Range::MIN)
      return (A[p1] <= A[p2]) ? p1 : p2;
    else // max
      return (A[p1] >= A[p2]) ? p1 : p2;
  }
};

int main() {
  clock_t t0 = clock();

  vector<int> A = {8, 7, 3, 9, 5, 1, 10};
  auto t = new SegmentTree(A);

  cout << "Range:\t";
  for (auto x : A)
    cout << x << " ";
  cout << endl << "Idx:\t";
  for (auto i = 0; i < A.size(); i++)
    cout << i << " ";
  cout << endl;

  // Starts from the root index 1
  t->build(Range::MIN, 1, 0, A.size() - 1);

  // index of minimum value in the sequence
  cout << "Range (1,3) min: " << t->rmq(Range::MIN, 1, 3) << endl; // -> 2
  cout << "Range (1,3) max: " << t->rmq(Range::MAX, 1, 3) << endl;

  clock_t t1 = clock();
  printf("\nRuntime = %.4f s\n", (t1 - t0) / (double)CLOCKS_PER_SEC);
  return 0;
}
