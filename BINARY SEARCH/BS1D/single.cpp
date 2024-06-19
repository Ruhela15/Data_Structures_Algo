#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return -1; // Handle edge case for empty array
    if (n == 1) return arr[0]; // Handle single element array
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the single element
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        // Adjust search space based on the pattern of pairs
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // This line should never be reached if input is valid
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int ans = singleElement(arr);
    if (ans != -1) {
        cout << "Single element is " << ans << endl;
    } else {
        cout << "No single element found or input array is invalid" << endl;
    }
    return 0;
}
