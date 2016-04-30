#include <iostream>
#include <vector>
using namespace std;

int row_max(int row, const vector<vector<int> >& lawn) {
    return *max_element(lawn[row].begin(), lawn[row].end());
}

int col_max(int col, const vector<vector<int> >& lawn) {
    int res = 0;
    for (int i = 0; i < lawn.size(); i++)
        res = max(res, lawn[i][col]);
    return res;
}

bool solve(int N, int M, const vector<vector<int> >& lawn) {
    vector<int> row_max_heights(N), col_max_heights(M);
    for (int i = 0; i < N; i++)
        row_max_heights[i] = row_max(i, lawn);
    for (int i = 0; i < M; i++)
        col_max_heights[i] = col_max(i, lawn);

    vector<vector<int> > made(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            made[i][j] = min(row_max_heights[i], col_max_heights[j]);
    
    return made == lawn;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M; cin >> N >> M;
        vector<vector<int> > lawn(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> lawn[i][j];

        string answer = solve(N, M, lawn) ? "YES" : "NO";
        cout << "Case #" << t << ": " << answer << endl;
    }
}
