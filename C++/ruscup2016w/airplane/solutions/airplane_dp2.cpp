#include <bits/stdc++.h>

int findMedian(long long s, const std::vector<long long>& sums) {
    std::vector<std::pair<int, long long>> as;
    for (size_t i = 0; i < sums.size(); i++) {
        if (sums[i] != 0) {
            as.push_back({i, sums[i]});
        }
    }
    long long needSum = s / 2;
    long long currentSum = 0;
    for (size_t i = 0; i < as.size(); i++) {
        currentSum += as[i].second;
        if (currentSum == needSum) {
            if (s % 2 == 0) {
                return (as[i].first + as[i + 1].first + 1) / 2;
            } else {
                return as[i + 1].first;
            }
        }
        if (currentSum > needSum) {
            return as[i].first;
        }
    }
    return -1;
}

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
    long long sumH = 0;
    long long sumV = 0;
    std::vector<long long> H(n);
    std::vector<long long> V(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            H[i] += a[i][j];
            V[j] += a[i][j];
            sumH += a[i][j];
            sumV += a[i][j];
        }              
    }
    int x = findMedian(sumH, H);
    int y = findMedian(sumV, V);
    printf("%d %d %lld", x + 1, y + 1, calcSum(a, x, y));
    return 0;
}
