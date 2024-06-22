#include<bits/stdc++.h>
using namespace std;
int sum (vector<int>arr,int div){
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=ceil((double)(arr[i])/(double)(div));
    } return sum;
}
int small(vector<int>arr,int theroshold){
    int n = arr.size();
    int maxi = INT_MIN ,mini = INT_MAX;
    for(int i =0; i<n; i++){
        maxi = max(maxi,arr[i]);
        mini= min(mini,arr[i]);
    }
    int low = mini,high = maxi;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(sum(arr,mid)<=theroshold){
            high = mid -1;
        }
        else{
            low  = mid+1;
        }
    }
    return low;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    int theroshold = 8;
    int ans = small(arr,theroshold);
    cout<<ans<<endl;
}