#include<bits/stdc++.h>
using namespace std;
int missing (vector<int>arr,int k ){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        int missingno = arr[mid] - (mid+1);
        if(missingno<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low+k;
}
int main(){
    vector<int>arr = {2,4,6,8,10};
    int k = 5;
    int ans = missing(arr,k);
    cout<<ans<<endl;
}