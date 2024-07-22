#include <bits/stdc++.h> 
using namespace std;

long long int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    long long int prev = nums[0];
    long long int prev2 = 0;
    for (int i = 1; i < n; i++) {
        long long int pick = nums[i];
        if (i > 1) pick += prev2;
        long long int notpick = prev;
        long long int cur = max(pick, notpick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (i != 0) temp1.push_back(valueInHouse[i]);
        if (i != n - 1) temp2.push_back(valueInHouse[i]);
    }
    return max(solve(temp1), solve(temp2));
}

int main() {
    vector<int> valueInHouse = {2, 3, 2};
    cout << houseRobber(valueInHouse) << endl;  // Output: 3
    return 0;
}
