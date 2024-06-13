#include<bits/stdc++.h>
using namespace std;
int secondSmallest(int arr[],int n){
    int smaller = INT_MAX;
  int secondsmaller = INT_MAX;
  for(int i = 0; i<n; i++){
    if(arr[i]<smaller){
        secondsmaller = smaller;
        smaller = arr[i];
    }
    else if(arr[i]<secondsmaller&&arr[i] !=smaller){
        secondsmaller = arr[i];
    }
  }
  return secondsmaller;
}
int secondLargest(int arr[],int n){
    int largest = INT_MIN;
    int secondlarge = INT_MIN;
    for(int i = 0; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
        else if(arr[i]>secondlarge&&arr[i]!=largest){
            secondlarge = arr[i];
        }
    }
    return secondlarge;
}
int main(){
     int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
        int sS=secondSmallest(arr,n);
        int sL=secondLargest(arr,n);
    cout<<"Second smallest is "<<sS<<endl;
    cout<<"Second largest is "<<sL<<endl;
    return 0;
}