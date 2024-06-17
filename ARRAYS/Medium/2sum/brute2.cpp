#include <bits/stdc++.h>
using namespace std;
vector<int> twosum(int n, vector<int> arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}
int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;
    vector<int> ans = twosum(n, arr, target);
    cout << "ans" <<" " << ans[0]<<","<<ans[1]<< endl;
}