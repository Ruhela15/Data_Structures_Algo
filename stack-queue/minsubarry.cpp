#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> s1, s2;

        // Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) s1.pop();
            ple[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        // Next Less Element (NLE)
        for (int i = 0; i < n; i++) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) s2.pop();
            nle[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        // Calculate the sum of minimums
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i], right = nle[i] - i;
            result = (result + arr[i] * left * right) % MOD;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of subarray minimums: " << sol.sumSubarrayMins(arr) << endl;
    return 0;
}
