#include<bits/stdc++.h>
using namespace  std;
void reverse(int arr[],int start,int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]  = temp;
        start ++;
        end--;
    }
}
 void rotated(int arr[],int n,int k ){
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-k-1);
    reverse(arr,0,n-1);
}
int main(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;
   rotated(arr,n,k);
   for(int i  = 0; i<n; i++){
    cout<<arr[i]<<" ";
   }

}