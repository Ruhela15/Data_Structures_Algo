#include<bits/stdc++.h>
using namespace std;
int minimum(vector<int>arr){
    int n = arr.size();
    int ans = INT_MAX;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[low]<=arr[high]){
            ans = min(ans,arr[low]);
            break;
        }
        else if(arr[low]<=arr[mid]){
            ans = min(ans ,arr[low]);
            low = mid+1;
        }
        else{
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}
int main(){
 
    vector<int>arr = {7,8,9,1,2,3,4,5,6};
    int ans = minimum(arr);
    cout<<" the minimum "<<ans<<" ";
}