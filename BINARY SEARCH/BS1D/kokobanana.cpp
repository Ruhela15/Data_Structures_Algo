#include<bits/stdc++.h>
using namespace std;
int findmax(vector<int>&arr){
    int maxi = INT_MIN;
    int n  = arr.size();
    for(int i = 0; i<n;i++){
        maxi = max(maxi ,arr[i]);
    }
    return maxi;
}
int calculatotalhours(vector<int>&arr,int hour){
    int totalH =0;
    int n = arr.size();
    for(int i = 0; i<n;i++){
        totalH +=ceil((double)arr[i])/(double)(hour);
    }
    return totalH;
}
int minimum(vector<int>&arr,int hour){
 int low = 1;
 int high = findmax(arr);
 while(low<=high){
    int mid = low+(high-low)/2;
    int totalH = calculatotalhours(arr,hour);
    if(totalH<=hour){
        high = mid-1;
    }
    else{
        low = mid+1;
    }

 }
 return low;
}
int main(){
    vector<int>arr = {7,11,2,3,4};
    int hour = 8;
    int ans = minimum(arr,hour);
        cout<<ans<<endl;
    
}