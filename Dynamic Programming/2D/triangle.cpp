
#include <bits/stdc++.h>
using namespace std;
int minimumPathSum(vector<vector<int> > &triangle, int n) {
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }


    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
           
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

         
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

int main() {
    // Define the triangle as a 2D vector
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle, n);

    return 0;
}

