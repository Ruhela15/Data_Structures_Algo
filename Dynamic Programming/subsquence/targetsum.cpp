#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization to find number of ways to partition the array
int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; // Special case: two subsets (empty subset and subset with zero sum)
        if (target == 0 || target == arr[0])
            return 1; // Only one subset (empty subset or single element subset)
        return 0;
    }
    
    if (dp[ind][target] != -1)
        return dp[ind][target];
    
    int nottake = solve(ind - 1, target, arr, dp);
    int take = 0;
    if (arr[ind] <= target)
        take = solve(ind - 1, target - arr[ind], arr, dp);
    
    return dp[ind][target] = (nottake + take);
}

// Main function to find the number of partitions with the given target sum
int targetSum(int n, int target, vector<int>& arr) {
    int totalsum = 0;
    for (int i = 0; i < n; i++) {
        totalsum += arr[i];
    }

    if (totalsum - target < 0 || (totalsum - target) % 2 == 1)
        return 0;

    int s2 = (totalsum - target) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return solve(n - 1, s2, arr, dp);
}

int main() {
    // Example usage
    vector<int> arr = {1, 1, 2, 3};
    int target = 1;
    int n = arr.size();
    cout << "Number of ways to partition the array: " << targetSum(n, target, arr) << endl;
    return 0;
}
