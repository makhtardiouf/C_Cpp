#include <bits/stdc++.h>

long long calcSum(const std::vector<std::vector<int>>& a, int x, int y) {
    long long value = 0;
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {   
            value += a[i][j] * 2LL * (std::abs(i - x) + std::abs(j - y) + 1);
        }
    }
    return value;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }              
    }
    long long bestSum = -1;
    int bestX = -1;
    int bestY = -1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            long long value = calcSum(a, x, y);
            if (bestSum == -1 || bestSum > value) {            
                bestSum = value;
                bestX = x;
                bestY = y;
            }
        }
    }
    printf("%d %d %lld", bestX + 1, bestY + 1, calcSum(a, bestX, bestY));
    return 0;
}
