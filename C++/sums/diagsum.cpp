

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
// Sum of diagonals

using namespace std;

int main()
{
    int n = 0;

    while (cin >> n) {
        int totD1 = 0;
        int totD2 = 0;
        std::vector< std::vector<int> > a(n, std::vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                clog << a[i][j] << " ";
            }
            clog << endl;
        }

        for (int i = 0, j = 1; j <= n; j++, i++) {
            totD1 += a[i][n - j];
        }
        clog << "Tot1 " << totD1 << endl;

        for (int i = 0; i < n; i++) {
            totD2 += a[i][i];
        }
        clog << "Tot2 " << totD2 << endl;
        cout << std::abs(totD1 - totD2) << endl;
    }

    return 0;
}
