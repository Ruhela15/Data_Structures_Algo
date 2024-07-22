#include<bits/stdc++.h>
using namespace std;
int main(){
        vector<int> nums = {2, 7, 9, 3, 1}; // Example input
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1;i<n;i++){
        int pick = nums[i];
        if(i>1) pick+=prev2;
        int notpick = 0+prev;
        int cur = max(pick,notpick);
        prev2 = prev;
        prev = cur;

    }
   cout<< prev;

}