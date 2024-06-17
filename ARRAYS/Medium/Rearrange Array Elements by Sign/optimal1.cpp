#include <bits/stdc++.h>
using namespace std;
vector<int> rearrange(vector<int> arr, int n)
{
vector<int>ans(n,0);
int posindex = 0, negindex = 1;
for(int i = 0; i<n; i++){
    if(arr[i]<0){
        ans[negindex] = arr[i];
        negindex+=2;
    }
    else{
        ans[posindex] = arr[i];
        posindex+=2;
    }
}
return ans;
}
int main()
{
    int n = 6;
    vector<int> arr{1, 2, -4, 3, -1, -5};
    vector<int> ans = rearrange(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}