#include<bits/stdc++.h>
using namespace std;
int findWays(vector<int>& arr, int k)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++)dp[i][0]=true;
    for(int j=0;j<=k;j++)
    {
        if(arr[0]==0)dp[0][arr[0]]=2;
        else if(arr[0]==j)dp[0][j]=1;
    }
   for(int i=1;i<n;i++)
   {
     for(int j=0;j<=k;j++)
       {
         int nottake=dp[i-1][j];
         int take=false;
         if(arr[i]<=j)take=dp[i-1][j-arr[i]];
         dp[i][j]=(take+nottake)%int(1e9+7);
       }
   }
return dp[n-1][k];
}
int main(){
    
}