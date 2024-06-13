#include <bits/stdc++.h>
using namespace std;
vector<int> missingrepeating(vector<int> arr)
{
    int n = arr.size();
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int repeating = -1, missing = -1;
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
            missing = i;
        else if (hash[i] == 2)
            repeating = i;

        if (missing != -1 && repeating != -1)
            break;
    }
    return {repeating, missing};
}
int main()
{
    vector<int> arr = {4, 1, 1, 2, 3, 6};
    vector<int> ans = missingrepeating(arr);
    cout << "the repeating no is " << ans[0] << endl
         << "the missing no is " << ans[1] << " ";
    return 0;
}