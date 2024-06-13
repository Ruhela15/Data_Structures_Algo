#include<bits/stdc++.h>
using namespace std;
int reversepair(vector<int>&arr,int n ){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>2*arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    vector<int>arr = {4, 1, 2, 3, 1};
    int n = arr.size();
    cout<<reversepair(arr,n)<<endl;
    }