/**
   Fenwick Tree, aka Binary Indexed Tree (BIT)
   used for dynamic cumulative frequency tables, and RSQ. P84
   g++ -std=c++11 ch2_10_fenwicktree_ds.cpp -o fenwicktree
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
// 1st Least Significant One-bit in S
#define LSOne(S) (S & (-S))

class FenwickTree
{
private:
    vi ft;

public:
    FenwickTree() {}
    FenwickTree(int n)
    {
        // ignore index 0
        ft.assign(n+1, 0);
    }

    // Additional sugar
    vector<int>::iterator begin()
    {
        return ft.begin();
    }
    vector<int>::iterator end()
    {
        return ft.end();
    }

    int rsq(int b)                                       // returns RSQ(1, b)
    {
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b)                                // returns RSQ(a, b)
    {
        printf("ft.rsq(%d, %d): ", a, b);
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v)
    {
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};

int main()                // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
{
    FenwickTree ft(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0}
    // Number of times each number appears in the sequence
    ft.adjust(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
    ft.adjust(4, 1);        // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
    ft.adjust(5, 2);        // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
    ft.adjust(6, 3);        // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
    ft.adjust(7, 2);        // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
    ft.adjust(8, 1);        // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
    ft.adjust(9, 1);        // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,10 => +1
    printf("Dynamic cumulative frequencies of each element: \n");
    for(auto e: ft)
        fprintf(stderr, "%d ", e);
    fprintf(stderr, "\n");

    // here rsq(b) = cf[1..b]
    printf("%d\n", ft.rsq(1, 1));  // 0 => ft[1] = 0
    printf("%d\n", ft.rsq(1, 2));  // 1 => ft[2] = 1
    printf("%d\n", ft.rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
    printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
    printf("%d\n", ft.rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1

    ft.adjust(5, 2); // update demo
    printf("%d\n", ft.rsq(1, 10)); // now 13
    for(auto e: ft)
        fprintf(stderr, "%d ", e);
    fprintf(stderr, "\n");
    return 0;
}
