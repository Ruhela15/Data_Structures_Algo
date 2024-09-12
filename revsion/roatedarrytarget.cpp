#include<iostream>
#include<vector>
using namespace std;
bool sortedarr(vector<int>arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==k) return true;
        else if(arr[mid]==arr[low]&&arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        else if(arr[low]<=arr[mid]){
            if(arr[low]<=k&&k<=arr[low]){
                high = mid-1;
            }
          else{
            low = mid+1;
          }
        }
        else{
            if(arr[high]>=k&&k<=arr[high]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return false;
    }

}
int main(){

}