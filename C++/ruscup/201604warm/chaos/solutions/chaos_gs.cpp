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
    sort(a.begin(), a.end());
    cout << (a[n - 1] + a[n - 2]) / 2 <<  endl;
    return 0;
}