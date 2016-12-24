// Segment or Interval Tree ds to determine min, max or sums of ranges
// No separation of interface vs implementation
#include "malib.h"
using namespace std;

template <typename T>
class SegmentTree
{

private:
  vector<T> segTree;
  vector<T> A;
  bool dbg = false;

  // Range operation
  T opt = 1; //, p = 1; //, parent node
  T b, e = 0;

  bool isInited = false;
  inline T left(T p)
  {
    return p << 1; // = 2*p
  }
  inline T right(T p)
  {
    return (p << 1) + 1; // = 2*p +1
  }

public:
  SegmentTree(vector<T> &A)
  {
    T N = A.size();
    this->A = A;

    // required tree length: 2*2^(floor(log2(N)) + 1)
    T length = (T)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    this->segTree.resize(length);
  }

  /**
     Populate the tree
     @param opt: Sum, Min, Max
     @param b: begin
     @param e: end
     * Complexity  O(n * log n)
     */
  void build(T opt, T p, T b, T e)
  {
    this->opt = opt;
    if (!isInited)
    {
      this->b = b;
      this->e = e;
      isInited = true;
    }

    // Leaf: begin == end
    if (b == e)
    {
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

    T lVal = this->segTree[left(p)];
    T rVal = this->segTree[right(p)];
    // if(dbg) clog << "lVal, rVal: " << lVal << ", " << rVal << endl;

    switch (opt)
    {
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

  // Range Min/Max Query
  T rmq(T opt, T i, T j)
  {
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
  T query(T opt, T p, T i, T j, T b = 0, T e = 6)
  {
    if (dbg)
      clog << "b, e " << b << ", " << e << endl;
    // Early sanity checks
    if (i > e || j < b)
      return -1;
    // inside query interval, return root node
    else if (b >= i && e <= j)
      return this->segTree[p]; //!!! issue here

    // minimum position on the Left/Right
    T p1 = query(opt, left(p), i, j, b, (b + e) / 2);

    T p2 = query(opt, right(p), i, j, (b + e) / 2 + 1, e);

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
