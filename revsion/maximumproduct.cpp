#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();  // Corrected .size to .size()
        int ans = INT_MIN;  // Initialize to the smallest possible integer
        int pre = 1, suf = 1;  // Initialize prefix and suffix products to 1
        
        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;  // Reset prefix product if it becomes 0
            if (suf == 0) suf = 1;  // Reset suffix product if it becomes 0
            
            pre = pre * nums[i];  // Update prefix product
            suf = suf * nums[n - i - 1];  // Update suffix product from the end of the array
            ans = max(ans, max(pre, suf));  // Update the answer with the maximum product found so far
        }
        return ans;  // Return the maximum product subarray
    }
};
