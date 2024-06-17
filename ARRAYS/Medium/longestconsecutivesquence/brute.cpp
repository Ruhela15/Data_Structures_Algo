#include<bits/stdc++.h>
using namespace std;
bool linear(vector<int>&a,int num){
    int n = a.size();
    for(int i = 0; i< n; i++){
        if(a[i]== num){
            return true;
        }
    }
    return false;
}
int longestconsecutive(vector<int>&arr){
    int n = arr.size();
    int longest = 1;
    for(int i = 0; i<n; i++){
        int x = arr[i];
        int cnt = 1;
          while (linear(arr,x+1)==true){
            x+=1;
            cnt+=1;
          }
          longest = max(longest ,cnt);
    }
return longest;
}
int main(){
    vector<int>arr = {100,200,1,2,3,4};
    int ans = longestconsecutive(arr);
    cout<<"longest squence " <<ans<<" ";
}