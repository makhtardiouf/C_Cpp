/* 8 Queens Chess Problem, solved with backtracking
 UVA 750, ICPC 5358
 solution ok for n rows/cols = 8 but not more
 g++ -lm -lcrypt -O2 -pipe ch3_01_UVa750.cpp
 Or -Og to enable optimizations that do not interfere with debugging
 */
#include <cstdlib>                       // int version of 'abs'
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> rows(8);
int lineCounter;

/**
   Can we place a queen at this row/col
   see if previously placed queens at not a threat
*/
bool cellOk(int r, int c)
{
    for (int prev = 0; prev < c; prev++) {

        // clash on same row or diagonal -> infeasible
        if (rows[prev] == r || (abs(rows[prev] - r) == abs(prev - c)))
            return false;
    }
    return true;
}

void backtrack(int c, int a, int b)
{
    // candidate sol, (a, b) has 1 queen
    if (c == 8 && rows[b] == a) {
        printf("%2d      %d", ++lineCounter, rows[0] + 1);
        for (int j = 1; j < 8; j++)
            printf(" %d", rows[j] + 1);
        printf("\n");
    }

    // all possible rows
    for (int r = 0; r < 8; r++)
        if (cellOk(r, c)) {
            // put queen here and recurse
            rows[c] = r;
            backtrack(c + 1, a, b);
        }
}

int main()
{
    int nCases = 0;
    cin >> nCases;
    while (nCases--) {
        int a, b = 0;
        cin >> a >> b;
        // switch to 0-based indexing
        a--;
        b--;
        rows.assign(rows.size(), 0);
        lineCounter = 0;

        cout << "SOLN\t   COLUMN\n";
        cout << " #\t1 2 3 4 5 6 7 8\n\n";

        // all possible 8! candidate solutions
        backtrack(0, a, b);
        if (nCases)
            cout << endl;
    }
    return 0;
}
