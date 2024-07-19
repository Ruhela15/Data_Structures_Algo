#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in) {
        if (root == NULL) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderval;
        inorder(root, inorderval);
        int i = 0, j = inorderval.size() - 1;
        while (i < j) {
            int sum = inorderval[i] + inorderval[j];
            if (sum == k) {
                return true;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;

    // Check if there exists a pair with sum k
    Solution sol;
    bool result = sol.findTarget(root, k);

    // Print the result
    if (result) {
        cout << "Found a pair with sum " << k << endl;
    } else {
        cout << "No pair with sum " << k << endl;
    }

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
