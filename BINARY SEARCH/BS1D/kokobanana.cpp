#include<bits/stdc++.h>
using namespace std;
int findmax(vector<int>arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int calculatehours(vector<int>arr,int hour){
 int n = arr.size();
 int totalh = 0;
 for(int i = 0; i<n; i++){
    totalh += ceil((double)(arr[i])/(double)(hour));
}
return totalh;
}
int minimum(vector<int>arr,int h){
    int low = 1;
    int high = findmax(arr);
    while(low<=high){
        int mid = low+(high-low)/2;
        int totalH = calculatehours(arr,mid);
        if(totalH<=h){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
     vector<int>arr = {7, 15, 6, 3};
     int hours = 8;
     int ans = minimum(arr,hours);
     cout<<ans<<endl;
}