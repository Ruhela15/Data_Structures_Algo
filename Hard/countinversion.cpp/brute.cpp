#include<bits/stdc++.h>
using namespace std;
int countinverion(vector<int>arr,int n){
    int cnt = 0; 
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    vector<int>arr ={5,3,2,4,1};
    int n = arr.size();
   cout<<countinverion(arr,n)<<" ";
}