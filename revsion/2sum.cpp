#include <iostream>
#include <vector>
#include <algorithm> // Include algorithm for sort

using namespace std;

vector<vector<int>> trisum(vector<int>& arr, int n) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue; // Correct duplicate check
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j-1]) j++; // Ensure valid bounds check
                while (j < k && arr[k] == arr[k+1]) k--; // Ensure valid bounds check
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> result = trisum(arr, n);

    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
