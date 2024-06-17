#include <bits/stdc++.h>
using namespace std;
int missing(vector<int> &arr, int n)
{
  int hashset[n+1] = {0};
  for(int i = 0; i<n-1; i++){
    hashset[arr[i]]++;
  }
  for(int i = 1; i<=n; i++){
    if(hashset[i]==0){
        return i;
    }
  }
  return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 5};
    int n = 5;
    int ans = missing(arr,n);
    cout<<"the missing element is"<<ans<<" ";
}