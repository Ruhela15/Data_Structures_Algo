#include <bits/stdc++.h>
using namespace std;
void sortedarr(vector<int> &arr, int n)
{
    int cnt0 = 0, cnt1 = 1, cnt2 = 2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cnt0++;
        }
        else if (arr[i] == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    for (int i = 0; i < cnt0; i++)

        arr[i] = 0;

    for (int i = cnt0; i < cnt0 + cnt1; i++)

        arr[i] = 1;

    for (int i = cnt0 + cnt1; i < n; i++)

        arr[i] = 2;
}
int main()
{
    int n = 6;
    vector<int> arr = {1, 0, 2, 2, 1, 0};
    sortedarr(arr, n);
    cout << "after soting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}