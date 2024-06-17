#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>fourt(vector<int>arr,int n, int target){
    set<vector<int>>st;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
             set<int>hashset;
            for(int k = j+1; k<n; k++){
                long long  sum = arr[i]+arr[j]+arr[k];
                long long fourth = target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int>temp = {arr[i],arr[j],arr[k],(int)(fourth)};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans ;
}
int main(){
    vector<int>arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int n = arr.size();
    int target = 9;
    vector<vector<int>>ans = fourt(arr,n,target);
    for(auto it:ans){
        cout<<"[";
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"]";
    }
    return 0;
}
