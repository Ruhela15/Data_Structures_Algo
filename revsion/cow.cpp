#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<int>&arr,int cow,int dis){
    int n = arr.size();
    int cowcnt = 1,last = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]-last>=dis){
            cowcnt++;
            last = arr[i];
        }
        if(cowcnt>=cow) return true;
    }
    return false;
}
int stall(vector<int>arr,int k ){
    int n =arr.size();
    int low  =0,high = arr[n-1]-arr[0];
    sort(arr.begin(),arr.end());
    while(low<=high){
        int mid = low+ (high-low)/2;
        if(check(arr,k,mid)==true){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}
int main(){

}