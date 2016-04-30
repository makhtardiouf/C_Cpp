#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 6 * 6 + 1;
int map[N][N];

bool check(vector<int> v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < (int) v.size(); ++i) {
        if (v[i] != i + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int m = n * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &map[i][j]);
            }
        }
        bool flag = true;
        for (int i = 0; i < m; ++i) {
            vector<int> v;
            for (int j = 0; j < m; ++j) {
                v.push_back(map[i][j]);
            }
            flag = flag && check(v);
        }
        for (int j = 0; j < m; ++j) {
            vector<int> v;
            for (int i = 0; i < m; ++i) {
                v.push_back(map[i][j]);
            }
            flag = flag && check(v);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<int> v;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        v.push_back(map[i * n + x][j * n + y]);
                    }
                }
                flag = flag && check(v);
            }
        }
        static int id = 0;
        printf("Case #%d: %s\n", ++id, flag ? "Yes" : "No");
    }
    return 0;
}
