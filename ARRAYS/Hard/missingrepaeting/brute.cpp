#include <bits/stdc++.h>
using namespace std;
vector<int> missingrepeating(vector<int> arr)
{
    int n = arr.size();
    int repeating = -1;
    int missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
                cnt++;
        }
        if (cnt == 2)
            repeating = i;
        else if (cnt == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
int main()
{
      vector<int> arr = {4, 1, 1, 2, 3, 6};
    vector<int> ans = missingrepeating(arr);
    cout << "the repeating no is " <<ans[0] <<endl << "the missing no is " << ans[1] << " ";
    return 0;
}