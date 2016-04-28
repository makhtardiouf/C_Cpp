/**
   Makhtar Diouf,  Hackerrank
   $Id$
  c++ -g -std=c++11 matrixsum.cpp -o matrixsum
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include "malib/malib.hpp"

using namespace std;
typedef vector< vector<int> > vvi;

class Matrix
{
public:
    vvi a;
    Matrix() {}
    Matrix(vvi& _a)
    {
        a = _a;
    }

    Matrix operator+(const Matrix& mb)
    {
        vvi b = mb.a;
        int n = a.size();
        int m = a[0].size();
        Matrix tot;
        vvi c(n, std::vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        tot.a = c;
        return tot;
    }
};

int main ()
{
    // part provided by the site
    int cases,k;
    cin >> cases;
    for(k=0; k<cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n,m,i,j;
        cin >> n >> m;
        
        for(i=0; i<n; i++) {
            vector<int> b;
            int num;
            for(j=0; j<m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        
        for(i=0; i<n; i++) {
            vector<int> b;
            int num;
            for(j=0; j<m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        
        result = x+y;
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
