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
pair<int, int> occurance(vector<int> &arr, int n, int k)
{
    int lb = lowerbond(arr, n, k);
    if (lb == n || arr[lb] != k)
        return {-1, -1};
    return {lb,upperbond(arr,n,k)-1};
}
int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5};
    int n = arr.size();
    int target = 3;
    pair<int,int>result = occurance(arr,n,target);
    cout<<"first occurance "<<result.first<<" last occurance "<<result.second<<endl;;
}