#include<bits/stdc++.h>
using namespace std;
void secondlargest (int arr[],int n){
    sort(arr,arr+n);
    int secondlargests = arr[n-2];
    int smaller = arr[1];
    cout<<"second largest "<<secondlargests<<" ";
    cout<<"second smaller "<<smaller<<" ";
}
int main(){
    int arr [] = {10,2,3,1,7};
    int n = 5;
    secondlargest(arr,n);
}