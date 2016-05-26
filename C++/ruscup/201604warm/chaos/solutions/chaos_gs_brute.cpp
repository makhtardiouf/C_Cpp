#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;

int ans;

void brute(const vector<int> &a) 
{
    if ((int)a.size() == 2)
    {
        assert(a[0] == a[1]);
        ans = max(ans, a[0]);
        //cerr << a[0] << endl;
    }
    else
    {
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = i + 1; j < (int)a.size(); j++)
                for (int k = j + 1; k < (int)a.size(); k++)
                {
                    vector<int> new_a;
                    for (int l = 0; l < (int)a.size(); l++)
                        if (l != i && l != j && l != k)
                            new_a.push_back(a[l]);
                    
                    vector<int> av(3);
                    av[0] = (a[i] + a[j]) / 2;
                    av[1] = (a[i] + a[k]) / 2;
                    av[2] = (a[j] + a[k]) / 2;
                    
                    for (int q = 0; q < 3; q++)
                    {
                        new_a.push_back(av[q]);
                        new_a.push_back(av[q]);
                        brute(new_a);
                        new_a.pop_back();
                        new_a.pop_back();
                    }
                }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    ans = 0;
    brute(a);
    cout << ans << endl;
    return 0;
}