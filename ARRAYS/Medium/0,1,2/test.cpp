#include<bits/stdc++.h>
using namespace std;
void sorted (vector<int>&arr,int n){
    int low = 0 , mid = 1,high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid--;
        }
        if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    vector<int>arr = {1,2,0,2,1,2,0,0,1,2};
    int n = arr.size();
    sorted(arr,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}