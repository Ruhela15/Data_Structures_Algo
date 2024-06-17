#include<bits/stdc++.h>
using namespace std;
int findappear(vector<int>&arr,int n){
    for(int i = 0; i<n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
        }
        if(cnt==1) return i;
    }

}
int main(){
 vector<int>arr {1,1,2,3,3,4,4,5,5,7,7,7};
 int n = arr.size();
 int ans = findappear(arr,n);
 cout<<ans<<endl;
}