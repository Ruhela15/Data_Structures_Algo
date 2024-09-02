#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(int ind, int target, vector<vector<int>>& ans, vector<int>& arr, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return; 
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue; 
            if (arr[i] > target) break; 

            ds.push_back(arr[i]);
            solve(i + 1, target - arr[i], ans, arr, ds); 
            ds.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, ans, candidates, ds);
        return ans; 
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5}; 
    int target = 8; 

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

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
