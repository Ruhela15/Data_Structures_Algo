 #include <bits/stdc++.h> 
 using namespace std;
int f(int ind, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (wt[0] <= w) return val[0];
        return 0;
    }
    if (dp[ind][w] != -1) return dp[ind][w];
    
    int nottake = f(ind-1, w, wt, val, dp);
    
    int take = INT_MIN;
    if (wt[ind] <= w) {
        take = val[ind] + f(ind-1, w - wt[ind], wt, val, dp);
    }
    
    return dp[ind][w] = max(nottake, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}