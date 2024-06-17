#include<bits/stdc++.h>
using namespace std;
void sortedarr(vector<int>&arr,int n){
    int low = 0, mid = 1, high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
             swap(arr[mid],arr[high]);
             high--;
        }
    }
}
int main(){
    int n = 6;
    vector<int>arr = {1,0,2,2,1,0};
    sortedarr(arr,n);
    cout<<"after sorting"<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}