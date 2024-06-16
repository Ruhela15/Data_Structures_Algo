#include<bits/stdc++.h>
using namespace std;
vector<int>leader(vector<int>arr,int n){
       vector<int>ans;
       int maxi  = arr[n-1];
       ans.push_back(arr[n-1]);
       for(int i = n-2; i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
       }
       return ans;
}
int main(){
    vector<int>arr ={10,22,12,3,0,6};
    int n = arr.size();
    vector<int>ans = leader(arr,n);
    for(int i = 0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}