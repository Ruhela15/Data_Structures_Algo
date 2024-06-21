#include <bits/stdc++.h>
using namespace std;
int fun(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int Nthroots(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midn = fun(mid, n, m);
        if (midn == 1)
        {
            return mid;
        }
        else if (midn == 2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n = 3, m = 27;
    int ans  = Nthroots(n,m);
    cout<<ans<<endl;
}