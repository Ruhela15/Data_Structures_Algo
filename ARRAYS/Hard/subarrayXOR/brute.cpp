#include<bits/stdc++.h>
using namespace std;
int subarrayxor(vector<int>arr,int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int  Xor = 0;
            for(int k = i; k<=j;k++){
                Xor = Xor^arr[k];
            }
            if(Xor==k) cnt++;
        }
    }
    return cnt;
}
int main(){
    vector<int>arr = {4,2,2,6,4};
    int k = 6;
    int ans = subarrayxor(arr,k);
    cout<<"subarry is "<<ans<<" ";
}