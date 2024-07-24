#include <bits/stdc++.h>
using namespace std;

int mode = 1e9 + 7;

int maze(int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1) {
                dp[i][j] = 0; // Obstacle
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1; // Starting point
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];
            dp[i][j] = (up + left) % mode;
        }
    }
    return dp[n - 1][m - 1];
}

int countPaths(int n, int m, vector<vector<int>>& mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return maze(n, m, mat, dp);
}

int main() {
    int n = 3, m = 3;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int result = countPaths(n, m, mat);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
