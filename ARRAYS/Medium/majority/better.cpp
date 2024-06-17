#include<bits/stdc++.h>
using namespace std;
int majority(vector<int>arr){
    int n = arr.size();
    map<int,int>mpp;
    for(int i = 0; i<n;i++){
        mpp[arr[i]]++;

    }
    for(auto it:mpp){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {1,2,2,3,4,2};
     int ans = majority(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
