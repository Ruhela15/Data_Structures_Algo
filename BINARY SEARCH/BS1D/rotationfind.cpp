#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int>&arr){

// Write your code here.

int n=arr.size(); 

int low=0;

int high=n-1;

int mid;

int index=-1;

int ans=INT_MAX;

while(low<=high)

{

    mid=(low+high)/2;

    if(arr[low]<=arr[high])

    {

        if(arr[low]<ans)

        {

            index=low;

            ans=arr[mid];

        }

        break;

    }

    if(arr[low]<=arr[mid])

    {

        if(arr[low]<ans)

        {

            index=low;

            ans=arr[low];

        }

        low=mid+1;

    }

    else

    {

        high=mid-1;

        if(arr[mid]<ans)

        {

            index=mid;

            ans=arr[mid];

        }

    }

}   

return index;
}
int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int rotations = findKRotation(arr);
    cout << "The array is rotated " << rotations << " times" << endl;
    return 0;
}