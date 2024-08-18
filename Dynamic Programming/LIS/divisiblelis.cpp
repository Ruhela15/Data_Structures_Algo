#include<bits/stdc++.h>
using namespace std;
vector<int>solve(vector<int>&arr){
int n = arr.size();
sort(arr.begin(),arr.end());
vector<int>dp(n,1);
vector<int>hash(n,1);
for(int i = 0;i<n;i++){
    hash[i] = i;
    for(int j = 0;j<i;j++){
        if(arr[i]%arr[j]==0&&1+dp[j]>dp[i]){
            dp[i] = 1+dp[j];
            hash[i] = j;
        }
    }
}
int ans  = -1;
int last = -1;
for(int i = 0;i<n;i++){
    if(dp[i]>ans){
        ans = dp[i];
        last = i;
    }
}
vector<int>temp;
temp.push_back(arr[last]);
while(hash[last]!=last){
last = hash[last];
temp.push_back(hash[last]);
}
reverse(temp.begin(),temp.end());
return temp;
} 
int main(){
    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> ans = solve(arr);

    cout << "The longest divisible subset elements are: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}