#include<bits/stdc++.h>
using namespace std;
int peek(vector<int> arr) {
    int n = arr.size();
    if (n == 0) return -1; 
    if (n == 1) return 0;  
    if (arr[0] > arr[1]) return 0;
    // if (arr[n - 1] < arr[n - 2]) return n - 2;
    
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4,13, 5, 6, 8, 7};
    int ans = peek(arr);
    cout << ans << endl; 
}


