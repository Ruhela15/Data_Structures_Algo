#include<bits/stdc++.h>
using namespace std;
vector<int>removezero(vector<int>arr, int n){
    vector<int> temp ;
    for(int i  = 0; i<n; i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int nz = temp.size();
    for(int i = 0; i<nz; i++){
            arr[i] = temp[i];
    }
    for(int i = nz; i<n; i++){
        arr[i] = 0;
    }
    return arr;
}
int main(){
    vector<int>arr = {1,2,0,3,4,0,5,0,2,3,0};
    int n = arr.size();
     vector<int>ans = removezero(arr,n);
     for(int i = 0; i<n;i++){
        cout<<ans[i]<<" "; 
     }
}