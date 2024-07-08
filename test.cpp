#include<bits/stdc++.h>
using namespace std;
int check(vector<int>arr,int k ){
    int cnt = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    vector<int>arr = {1, 5, 7, 1};
    int k = 6;
    int ans  = check(arr,k);
    cout<<ans;
}
