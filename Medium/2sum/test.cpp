#include<bits/stdc++.h>
using namespace std;
string sum(vector<int>arr,int n ,int target){
  sort(arr.begin(),arr.end());
  int left = 0,right = n-1;
  while(left<=right){
   int sum = arr[left]+arr[right];
   if(sum==target){
      return "YES";
   }
   else if(sum<target) left ++;
   else right--;
  }
  return "NO";
}
int main(){
   vector<int>arr = {1,2,3,4,5};
   int n = arr.size();
   int target = 10;
    cout<<sum<<endl;
   
}
