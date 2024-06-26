#include<bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>>mat,int n,int m,int target){
    int low = 0; 
    int high = (n*m-1);
    while(low<=high){
        int mid = low+(high-low)/2;
        int row = mid/m;
        int col = mid%m;
        if(mat[row][col]==target) return true;
        else if(mat[row][col]<target) low = mid+1;
        else high = mid+1;
    }
    return false;
}
int main(){
    vector<vector<int>>mat = {{1,2,3},{4,5,6},{7,8,9}};
    int n = mat.size();
    int m = mat[0].size();
    int target = 7;
    int ans  = search(mat,n,m,target);
    cout<<ans<<endl;
}