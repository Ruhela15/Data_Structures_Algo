#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findmax(vector<int>& v) {
        int maxi = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int calculate(vector<int>& v, int hourly, int h) {
        int totalh = 0;
        for (int i = 0; i < v.size(); i++) {
            totalh += ceil((double)v[i] / (double)hourly);
            if (totalh > h) break;
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1, high = findmax(v);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalh = calculate(v, mid, h);
            if (totalh <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
