#include <bits/stdc++.h>
using namespace std;

int lowerbond(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperbond(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int lb = lowerbond(arr, n, k);
    if (lb == n || arr[lb] != k)
        return {-1, -1};
    int ub = upperbond(arr, n, k);
    return {lb, ub - 1};
}

int count(vector<int> &arr, int n, int x)
{
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1)
        return 0;
    return ans.second - ans.first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5};
    int n = arr.size();
    int target = 3;
    pair<int, int> result = firstAndLastPosition(arr, n, target);
    cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << endl;
    cout << "Count of target: " << count(arr, n, target) << endl;
    return 0;
}
