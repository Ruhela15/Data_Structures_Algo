#include<bits/stdc++.h>
using namespace std;
int f(int n,vector<int>&nums,vector<int>&dp){
    dp[0] = nums[0];
    for(int i = 1;i<n;i++){
        int pick = nums[i];
        if(i>1) pick+=dp[i-2];
        int  notpick = dp[i-1];
        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
}
int main(){
 vector<int> nums = {2, 7, 9, 3, 1}; // Example input
    int n = nums.size();
    vector<int> dp(n, -1);
    
    int result = f(n - 1, nums, dp);
    cout << "Maximum sum of non-adjacent elements: " << result << endl;
    return 0;
}