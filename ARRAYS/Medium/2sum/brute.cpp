#include<bits/stdc++.h>
using namespace std;
string sum(int n,vector<int>arr,int target){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n;j++){
            if(arr[i]+arr[j] == target)
            return "yes";
        }
    }
    return "no";
}
int main(){
    int n = 5;
    vector<int>arr = {1,2,3,4,5};
    int target  = 8;
     string  ans = sum( n,arr,target);
     cout<<"the answer is "<< ans<<endl;
     return 0;
}