#include <bits/stdc++.h>
using namespace std;
int missing(vector<int> &arr, int n)
{
    int sum1 = (n * (n + 1)) / 2;
    int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s2 += arr[i];
    }
    int ans = sum1 - s2;
    return ans; 
}
int main()
{
    vector<int> arr = {1, 2, 3, 5};
    int n = 5;
    int ans = missing(arr,n);
    cout<<"the missing element is"<<ans<<" ";
}