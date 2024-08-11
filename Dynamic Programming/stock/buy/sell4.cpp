#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Recursive function with memoization to compute the maximum profit
int solve(int ind, int buy, const vector<int>& prices, vector<vector<int>>& dp) {
    // Base case: if we're past the last day, no profit can be made
    if (ind >= prices.size()) {
        return 0;
    }

    // Check if the result is already computed
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    // If we're in a buying state
    if (buy == 1) {
        // We can either buy today or skip to the next day
        return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, prices, dp),
                                 solve(ind + 1, 1, prices, dp));
    } else { // We're in a selling state
        // We can either sell today or skip to the next day
        return dp[ind][buy] = max(prices[ind] + solve(ind + 2, 1, prices, dp),
                                 solve(ind + 1, 0, prices, dp));
    }
}

// Function to initialize the DP table and start the recursion
int stockProfit(const vector<int>& prices) {
    int n = prices.size();
    // Initialize DP table with -1 to indicate uncomputed states
    vector<vector<int>> dp(n, vector<int>(2, -1));
    // Start from day 0 with the ability to buy
    return solve(0, 1, prices, dp);
}

// Example usage
int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Maximum profit: " << stockProfit(prices) << endl;
    return 0;
}
