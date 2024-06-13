#include <bits/stdc++.h>
using namespace std;

vector<int> generaterow(int row) {
    vector<int> ansrow(row + 1);  // To store the entire row, including the 0th index
    long long ans = 1;
    ansrow[0] = 1;  // The first element is always 1

    for (int col = 1; col <= row; col++) {
        ans = ans * (row - col + 1) / col;
        ansrow[col] = ans;
    }
    return ansrow;
}

vector<vector<int>> pascaltriangle(int n) {
    vector<vector<int>> ans;
    for (int row = 0; row < n; row++) {  // Loop from 0 to n-1
        ans.push_back(generaterow(row));
    }
    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> ans = pascaltriangle(n);
    
    for (const auto& row : ans) {
        for (int ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}
