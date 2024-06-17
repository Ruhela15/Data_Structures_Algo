#include<bits/stdc++.h>
using namespace std;
void rotated(vector<vector<int>>&arr){
    int n = arr.size();
    for(int i = 0;i<n-1;i++){
        for(int j =i+1; j<n;j++ ){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i = 0; i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}
int main(){
    vector<vector<int>>arr;
    arr = {{1,2,3},{4,5,6},{7,8,9}};
     rotated(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "n";
}
}