#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int ind, int n, const vector<int>& price, vector<vector<int>>& dp) {
    if (ind == 0) {
        return n * price[0];
    }
    if (dp[ind][n] != -1) return dp[ind][n];
    
    int notake = solve(ind - 1, n, price, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    
    if (rodlength <= n) {
        take = price[ind] + solve(ind, n - rodlength, price, dp);
    }
    
    return dp[ind][n] = max(notake, take);
}

int cutRod(const vector<int>& price, int n) {
    vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
    return solve(price.size() - 1, n, price, dp);
}
