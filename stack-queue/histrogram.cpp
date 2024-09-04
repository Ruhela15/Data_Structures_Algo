#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? n : n - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << solution.largestRectangleArea(heights) << endl;
    return 0;
}

