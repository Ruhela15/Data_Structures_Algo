#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];  // Extend the common substring
                ans = max(ans, dp[i][j]);  // Update the result
            } else {
                dp[i][j] = 0;  // Reset if characters do not match
            }
        }
    }

    return ans;  // Return the length of the longest common substring
}
