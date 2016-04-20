/**
   Competitive programming library constructs: 
 * Segment tree  stored like a heap array, used for
   Static Range Minimum/Maximum/Sum queries.
   Makhtar diouf
   $Id$
   g++ -g -Wall -std=c++11 segment_tree.cpp -o segment_tree
 */
#include "malib.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

enum Range
{
    SUM = 0,
    MIN,
    MAX
};

class SegmentTree
{
private:
    vector<int> segTree;
    vector<int> A;
    int opt, node = 1;
    int b, e = 0;
    bool isInited = false;

public:

    SegmentTree(vector<int> &A)
    {
        int N = A.size();
        this->A = A;
        // required array length: 2*2^(floor(log2(N)) + 1)
        int length = (int) (2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
        this->segTree.resize(length);
    }

    /**
     * @param opt: Sum, Min, Max
       @param b: begin
       @param e: end
     * Complexity  O(n * log n)
     */
    void buildSegTree(int opt, int node, int b, int e)
    {
        this->opt = opt;
        this->node = node;
        if (!isInited)
        {
            this->b = b;
            this->e = e;
            isInited = true;
        }

        // Leaf
        if (b == e)
        {
            if (opt == Range::SUM)
                this->segTree[node] = this->A[b]; // store value
                // MIN/MAX, store index
            else
                this->segTree[node] = b;
            // No subtrees from leafs
            return;
        }

        // Recursively compute the values in the Left and Right subtrees
        int lIdx = 2 * node;
        int rIdx = lIdx + 1;
        buildSegTree(opt, lIdx, b, (b + e) / 2);
        buildSegTree(opt, rIdx, (b + e) / 2 + 1, e);

        int lVal = this->segTree[lIdx];
        int rVal = this->segTree[rIdx];
        switch (opt)
        {
        case Range::SUM:
            this->segTree[node] = lVal + rVal;
            break;
        case Range::MAX:
            this->segTree[node] = (this->A[lVal] >= this->A[rVal]) ? lVal : rVal;
            break;
        default:
            // MIN
            this->segTree[node] = (this->A[lVal] <= this->A[rVal]) ? lVal : rVal;
        }
    }

    /**
     *  Complexity  O(log n)
     * 
     */
    int query(int opt, int i, int j, int b = -1, int e = -1)
    {
        b = (b == -1 ? this->b : b);
        e = (e == -1 ? this->e : e);

        // Early sanity checks
        if (i > e || j < b)
            return -1;
            // inside query interval
        else if (b >= i && e <= j)
            return this->segTree[this->node];

        // compute the minimum position on the Left/Right
        int p1 = query(opt, i, j, b, (b + e) / 2);
        int p2 = query(opt, i, j, (b + e) / 2 + 1, e);

        // position where the overall minimum is
        if (p1 == -1) return p2; // segment outside query
        if (p2 == -1) return p1;

        if (opt == Range::SUM)
            return p1 + p2;
        else if (opt == Range::MIN)
            return (this->A[p1] <= this->A[p2]) ? p1 : p2;
        else // max
            return (this->A[p1] >= this->A[p2]) ? p1 : p2;
    }
};

int main()
{
    vector<int> A = {8, 7, 3, 9, 5, 1, 10};
    auto t = new SegmentTree(A);
    t->buildSegTree(Range::MIN, 1, 0, 6);

    // Determine the index of minimum value in the sequence
    cout << t->query(Range::MIN, 1, 3) << endl; // -> 2
    return 0;
}
