#include<bits/stdc++.h>
using namespace std;
int lower_bond(vector<int>arr,int n,int x){
    int low = 0; 
    int high = n-1;
    int ans  = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>=x){
            ans  = mid;
         high  = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans ;
}
int maximum(vector<vector<int>>mat,int n ,int m){
    int cnt_max =0;
    int index = -1;
    for(int i = 0; i<n; i++){
        int cnt_ones = m-lower_bond(mat[i],m,1);
        if(cnt_ones>cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main() {
    vector<vector<int>> matrix = {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}, {1, 1, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = maximum(matrix, n, m);
    cout << ans << endl;
    return 0;
}