#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>arr,int cow,int dis){
    int cntcows =  1;
    int last = arr[0];
    int n = arr.size();
    for(int i = 1; i<n;i++){
        if(arr[i]-last>=dis){
            cntcows++;
            last = arr[i];
        }
       if(cntcows>=cow){
        return true;
       }
    }
    return false;
}
int aggresive(vector<int>arr,int k){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[n-1] -arr[0];
    while(low<=high){
    int mid = low+(high-low)/2;
    if(ispossible(arr,k,mid)==true){
        low = mid+1;
    }
    else{
        high = mid-1;
    }
    }
    return high;
}
int main(){
    vector<int>arr = {0,3,4,7,9,10};
    int cows = 4;
    int ans  = aggresive(arr,cows);
    cout<<ans<<endl;

}