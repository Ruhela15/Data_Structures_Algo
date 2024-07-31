#include <vector>
using namespace std;

long solve(vector<int>& arr, int ind, int t, vector<vector<long>>& dp) {
    if (ind == 0) {
        return (t % arr[0] == 0);
    }
    if (dp[ind][t] != -1) return dp[ind][t];
    
    long nottake = solve(arr, ind - 1, t, dp);
    long take = 0;
    if (arr[ind] <= t) {
        take = solve(arr, ind, t - arr[ind], dp);
    }
    return dp[ind][t] = nottake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<int> coins(denominations, denominations + n);
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve(coins, n - 1, value, dp);
}
