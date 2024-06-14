#include<bits/stdc++.h>
using namespace std;
vector<int>unio(vector<int>&arr1,int n,vector<int>&arr2,int m){
set<int>s;
for(int i = 0; i<n; i++){
    s.insert(arr1[i]);
}
for(int i = 0; i<m; i++){
    s.insert(arr2[i]);
}
vector<int>temp (s.begin(),s.end());
return temp;
}
int main(){
    vector<int>arr1 = {1,2,2,3,3,4,5};
    int n  = arr1.size();
    vector<int>arr2 = {2,2,3,4,5,5,6};
    int m = arr2.size();
    vector<int>ans = unio(arr1,n,arr2,m);
   for(int i =0 ; i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
}