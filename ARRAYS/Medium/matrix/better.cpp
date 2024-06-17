#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>zeromatrix(vector<vector<int>>&matrix,int n,int m){
    int row[n] = {0};
    int coln[m] = {0};
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            if(matrix[i][j]==0){
                    row[i] = 1;
                    coln[j] = 1;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i]||coln[j]){
               matrix[i][j] = 0;
            }
        }
    }
    return matrix ;
}
int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeromatrix(matrix,n,m);
    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}