#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    if (ind >= n || cap == 0) return 0;
    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    
    int profit = 0;
    if (buy == 0) {
        profit = max(-prices[ind] + solve(prices, n, ind + 1, 1, cap, dp),
                     0 + solve(prices, n, ind + 1, 0, cap, dp));
    }
    if (buy == 1) {
        profit = max(prices[ind] + solve(prices, n, ind + 1, 0, cap - 1, dp),
                     0 + solve(prices, n, ind + 1, 1, cap, dp));
    }
    return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int>& prices, int n, int k) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solve(prices, n, 0, 0, k, dp);
}
