/**
Hrank variable sized arrays, using only pointers and iostream
Makhtar Diouf
$Id$
https://www.hackerrank.com/challenges/variable-sized-arrays
*/

#include <iostream>
using namespace std;

int main()
{
    typedef unsigned long ul;
    ul N, Q, K = 0;
    cin >> N >> Q;

    ul **V = new ul* [N];
    ul val;

    for(ul n=0; n<N; n++) {
         cin >> K;
        //  clog << "N, K: " << N << " " << K << endl;
        ul* cols = new ul [K];
        for(ul k=0; k < K; k++) {
            cin >> val ;
            cols[k] = val;
           // clog << val << " ";
        }
        *(V+n) = cols;
        clog << endl;         
    }

    ul a, b = 0;
    for(ul q=0; q<Q; q++) {
        cin >> a >> b;
        //  clog << "a, b: " << a << " " << b << endl;
        cout << V[a][b] << endl;
    }
    
// delete[] V;
    return 0;
}
