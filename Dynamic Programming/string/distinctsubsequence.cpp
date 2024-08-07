#include <iostream>
#include <vector>
#include <string>

const int prime = 1e9 + 7;

int distinctSubsequences(const std::string &str, const std::string &sub) {
    int n = str.length();
    int m = sub.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    // Initialize the dp table
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1; // An empty subsequence can always be formed
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str[i - 1] == sub[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    std::string str = "rabbbit";
    std::string sub = "rabbit";
    std::cout << "Distinct subsequences: " << distinctSubsequences(str, sub) << std::endl;
    return 0;
}
