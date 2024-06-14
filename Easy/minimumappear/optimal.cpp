#include <bits/stdc++.h>
using namespace std;

int findUniqueElement(vector<int>& arr, int n) {
    int Xor = 0;
    for (int i = 0; i < n; i++) {
        Xor ^= arr[i];
    }
    return Xor;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 5, 5, 7, 7};
    int n = arr.size();
    int ans = findUniqueElement(arr, n);
    cout << "The element that appears exactly once is: " << ans << endl;
    return 0;
}
