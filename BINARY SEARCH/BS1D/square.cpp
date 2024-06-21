#include<bits/stdc++.h>
using namespace std;
int squares(vector<int>arr,int n,int sq){
  int low = 0;
  int high = n-1;
  int ans  = 0;
  while(low<=high){
    long long mid = low+(high-low)/2;
    long long val = arr[mid]*arr[mid];
    if(val<=sq){
        low = mid+1;
        ans = arr[mid];
    }
    else{
        high = mid-1;
    }
  }
  return ans;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    int n = arr.size();
    int sq = 7;
    int ans  = squares(arr,n,sq);
    cout<<ans<<endl;
}