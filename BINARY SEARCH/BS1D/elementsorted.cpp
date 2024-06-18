#include<bits/stdc++.h>
using namespace std;
int searche(vector<int>arr,int n , int x){
    int low = 0; 
    int high = n-1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]==x) return mid;
        if(arr[low]<=x){
            if(arr[low]<=x&&arr[mid]<x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(x<=arr[high]&&x<arr[mid]){
                low = mid+1;
            }
            else{
                high  = mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {7,8,9,1,2,3,4,5,6};
    int n = arr.size();
    int target = 2;
    int ans  = searche(arr,n,target);
    cout<<ans<<" ";
}