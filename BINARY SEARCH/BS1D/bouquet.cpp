#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr, int day, int m, int k)
{
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int minimum(vector<int> arr, int m, int k)
{
    int n = arr.size();
    int val = m * k;
    if (val > n)
        return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(arr, mid, m, k))
        {
            high = mid - 1;
        }
        else
        {
            low = mid +1;
        }
    }
    return low;
}
int main()
{
    vector<int>arr = {7,7,7,7,13,11,12,7};
 int m = 2;
    int k = 3;
    int ans = minimum(arr, m, k);
    cout << ans << endl;
}