#include<bits/stdc++.h>
using namespace std;
int solve(int n ,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            if(i==0&&j==0) dp[i][j] = grid[i][j];
            else{
                int up = grid[i][j];
                int left = grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                if(j>0) left+=grid[i][j-1];
                else left+=1e9;
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}
int countPaths(int n, int m, vector<vector<int>>& mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n, m, mat, dp);
}

int main() {
    int n = 3, m = 3;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int result = countPaths(n, m, mat);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
