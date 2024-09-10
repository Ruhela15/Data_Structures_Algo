#include<iostream>
#include<map>
#include<vector>
using namespace std;
int subarray(vector<int>arr,int k){
    int n = arr.size();
    int xr = 0;
    map<int,int>mp;
    mp[xr]++;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        xr = xr^arr[i];
        int x = xr^k;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt ;
}
int main(){
vector<int>arr = {1,2,3,4,5,6};
int k =7;
}