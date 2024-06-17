#include <bits/stdc++.h>
using namespace std;
vector<int> rearrange(vector<int> arr, int n)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)

            pos.push_back(arr[i]);

        else

            neg.push_back(arr[i]);
    }

        for (int i = 0; i < n / 2; i++){

            arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
        }
    return arr;
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
