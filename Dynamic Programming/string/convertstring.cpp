#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(const string& s, const string& t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {  // Fix: changed from i < n to i <= n
        for (int j = 1; j <= m; ++j) {  // Fix: changed from j <= m to j <= m
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int canYouMake(const string& s1, const string& s2) {
    int solvelength = solve(s1, s2);
    return (s1.length() + s2.length() - 2 * solvelength);
}
