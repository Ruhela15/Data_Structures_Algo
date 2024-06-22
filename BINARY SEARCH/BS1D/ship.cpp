#include<bits/stdc++.h>
using namespace std;
int totald(vector<int>arr,int cap){
    int days = 1;
    int load = 0;
    int n = arr.size();
    for(int i = 0; i<n;i++){
       if(load +arr[i]>cap){
        days++;
        load = arr[i];
       }
       else{
        load +=arr[i];
       }
    }
    return days;
}
int ships(vector<int>arr , int d ){
    int n = arr.size();
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = low +(high-low)/2;
        if(totald(arr,mid)<=d){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
    vector<int>arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = ships(arr,d);
    cout<<ans<<" ";
}