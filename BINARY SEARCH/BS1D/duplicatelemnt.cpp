#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>&arr,int n ,int x){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==x)return "true";
        else if(arr[mid]==arr[low]&&arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        else if(arr[low]<=arr[mid]){
            if(arr[low]<=x&&arr[mid]>x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(x<=arr[high]&&arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return "false";
}
int main(){
    vector<int>arr = {3,3,1,1,3,3,3,3};
    int n = arr.size();
    int target = 3;
    int ans = search(arr,n,target);
    cout<<ans<<endl;
}