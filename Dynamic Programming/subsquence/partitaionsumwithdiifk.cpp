#include <bits/stdc++.h> 
using namespace std;
int mod = (int)(1e9+7);
int solve(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
     if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int nottake = solve(ind-1,target,arr,dp);
    int take = 0;
    if(arr[ind]<=target){
        take = solve(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target] = (nottake+take)%mod;
}
int findway(vector<int>&arr,int target){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(n-1,target,arr,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum = 0;
    for(auto&it:arr) totalsum+=it;
    if(totalsum-d<0||(totalsum-d)%2){
        return false;
    }
    return findway(arr,(totalsum-d)/2);
}

int main() {

  vector<int> arr = {0,0,1};
  int k=1;
                                 
  cout<<"The number of subsets found are " <<findway(arr,k);
}