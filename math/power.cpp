#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        for (int i = 0; i < n; i++) {
            ans *= x;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    double x = 2.0;
    int n = 10;
    std::cout << "Result: " << solution.myPow(x, n) << std::endl;
    return 0;
}
