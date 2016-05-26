#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    int res1 = -1, res2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= res1)
            res2 = res1, res1 = a[i];
        else if (a[i] > res2)
            res2 = a[i];
    }
    cout << (res1 + res2) / 2 << endl;
    return 0;
}