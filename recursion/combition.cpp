#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(int ind, int target, vector<vector<int>>& ans, vector<int>& arr, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (ind >= arr.size()) {
            return;
        }

        // Include the current element if it's less than or equal to the target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            solve(ind, target - arr[ind], ans, arr, ds); // Note: not incrementing index here to allow multiple usage of the same element
            ds.pop_back(); // Backtrack
        }
        // Move to the next element
        solve(ind + 1, target, ans, arr, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, ans, candidates, ds);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7}; // Example candidates
    int target = 7; // Example target

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << " are:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
