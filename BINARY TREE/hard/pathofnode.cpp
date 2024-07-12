#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class sol {
public:
    bool getpath(Node* root, vector<int>& arr, int x) {
        if (!root) return false;
        arr.push_back(root->data);
        if (root->data == x) return true;
        if (getpath(root->left, arr, x) || getpath(root->right, arr, x)) return true;
        arr.pop_back();
        return false;
    }

    vector<int> solve(Node* a, int b) {
        vector<int> arr;
        if (a == nullptr) {
            return arr;
        }
        getpath(a, arr, b);
        return arr;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    sol solution;
    vector<int> path = solution.solve(root, 5);

    cout << "Path to 5: ";
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
