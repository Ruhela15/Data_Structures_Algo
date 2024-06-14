#include<bits/stdc++.h>
using namespace std;
vector<int>intersection(vector<int>arr1 ,int n, vector<int>arr2,int m){
    int i =0 , j = 0;
    vector<int>ans;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
        i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    vector<int>arr1 = {1,2,3,4,4,5,6};
    int n = arr1.size();
    vector<int>arr2 = {2,3,4,5,6,6,7};
    int m = arr2.size();
    vector<int>ans = intersection(arr1,n,arr2,m);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}