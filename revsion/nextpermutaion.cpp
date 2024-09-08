#include <iostream>
#include <vector>
using namespace std;
vector<int> nextp(vector<int> &a, int n)
{
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (a[i] > a[ind])
        {
            swap(a[i],a[ind]);
        }
        break;
    }
     reverse(a.begin() + ind + 1, a.end());

    return a;
}
int main()
{
        vector<int> a = {2, 1, 5, 4, 3, 0, 0};
        int n = a.size();
    vector<int> ans = nextp(a ,n);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;

}