#include<bits/stdc++.h>
using namespace std; 

int nCr(int n, int r) {
    long long ans = 1;
    for(int i = 0; i < r; i++) {
        ans = ans * (n - i);  // multiply by (n-i)
        ans = ans / (i + 1);  // divide by (i+1)
    }
    return ans;
}

int pascaltriangle(int r, int c) {
    int element = nCr(r - 1, c - 1); // Pascal's triangle is 1-indexed
    return element;
}

int main() {
    int r = 5;
    int c = 3;
    int element = pascaltriangle(r, c);
    cout << "The element is " << element << " ";
    return 0;
}
