#include <bits/stdc++.h>
using namespace std;

int solve(const string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int minimumInsertions(const string &str) {
    return str.length() - solve(str);
}

int main() {
    string str = "abcb";
    cout << "Minimum insertions required: " << minimumInsertions(str) << endl;
    return 0;
}
