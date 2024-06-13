#include<bits/stdc++.h>
using namespace std;
string twosum (vector<int>&arr,int n , int target){
    sort(arr.begin(),arr.end());
    int left = 0 , right = n-1;
    while(left<right){
     int sum = arr[left] + arr[right];
     if(sum == target){
        return "yes";
     }
     else if(sum<target) {
        left++;
     }
     else{
        right--;
     }
    }
    return "no";
}
int main(){
    int n = 5;
    vector<int>arr = {1,2,3,4,5};
    int target = 5;
     string ans = twosum(arr,n, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}