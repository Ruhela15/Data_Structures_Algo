#include<iostream>
using namespace std;
int kadane(int arr[],int n){
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i = 0;i<n;i++){
        sum+=arr[i];
        if(sum>maxsum){
            maxsum = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maxsum;
}
int main(){
int arr[6] = {1,-2,3,4,5};
int n = 6;

}