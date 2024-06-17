#include<bits/stdc++.h>
using namespace std;
int findmax(vector<int>&arr,int n){
    int maxi = 0; 
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
}
int main(){
    vector<int>arr = {1,1,0,1,1,1,1,0,2,2,2,3,0,3,1};
    int n  = arr.size();
    int ans = findmax(arr,n);
    cout<<ans<<endl;
    
}