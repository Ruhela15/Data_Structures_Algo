#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // Create a 2D vector to store the DP results
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        // Initialize the base cases
        for (int i = 0; i <= n; ++i) dp[i][0] = i;  // Cost of deleting all characters from word1
        for (int j = 0; j <= m; ++j) dp[0][j] = j;  // Cost of inserting all characters into word1
        
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // Characters match, no extra cost
                } else {
                    dp[i][j] = 1 + std::min({dp[i - 1][j],     // Delete
                                             dp[i][j - 1],     // Insert
                                             dp[i - 1][j - 1]}); // Replace
                }
            }
        }
        
        // Return the minimum distance between the two strings
        return dp[n][m];
    }
};
