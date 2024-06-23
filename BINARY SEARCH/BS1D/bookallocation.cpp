#include<bits/stdc++.h>
using namespace std;
int countp(vector<int>arr,int pages){
    int n = arr.size();
    int student = 1;
    long long countpages = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]+countpages <=pages){
            countpages += arr[i];
        }
        else{
            countpages = arr[i];
            student++;
        }
    }
    return student;

}
int minimumd(vector<int>arr,int m){
    int n = arr.size();
    int low = *max_element(arr.begin(),arr.end());
    int high  =  accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = low+(high-low)/2;
        if(countp(arr,mid)>m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
int main(){
   vector<int>arr = {25,46,28,48,24};
   int m = 4;
   int ans  = minimumd(arr,m);
   cout<<ans<<endl;
}