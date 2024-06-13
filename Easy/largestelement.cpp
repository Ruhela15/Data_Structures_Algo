#include<bits/stdc++.h>
using namespace std;
int large (vector<int>arr,int n){
    int largest = arr[0];
    for(int i = 0; i<n;i++){
    if(arr[i]>largest)
        largest = arr[i];
    
    }
    return largest;
}
int main(){
    vector<int>arr = {5,4,3,2,1};
    int n = arr.size();
    int ans = large(arr,n);
    cout<<"largest element is "<< ans<<" ";
}