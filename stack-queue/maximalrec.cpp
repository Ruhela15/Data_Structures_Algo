#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        stack<int>s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int height = heights[s.top()]; s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};
