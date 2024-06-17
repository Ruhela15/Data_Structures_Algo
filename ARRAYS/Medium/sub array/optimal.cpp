#include<bits/stdc++.h>
using namespace std;
long long  maxsum(vector<int>&arr ,int n){
    long long maxi = INT32_MIN;
    long sum = 0;
    for(int i = 0; i<n; i++){
        sum+=arr[i];
        if(sum>maxi){
         maxi = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
    
   
}
int main(){
     int n  = 9;
     vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
     int max = maxsum(arr,n);
     cout<<"the maximum subarray is "<<max<<endl;
     return  0;
}