#include <iostream>
#include <climits>
#include <algorithm>

// Definition for a binary tree node
class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Class to store information about each subtree
class info {
public:
    int maxi;
    int mini;
    bool isbst;
    int size;

    info(int maxVal, int minVal, bool bst, int sz)
        : maxi(maxVal), mini(minVal), isbst(bst), size(sz) {}
};

// Helper function to find the largest BST in a binary tree
info solve(TreeNode* root, int &ans) {
    if (root == NULL) {
        return info(INT_MIN, INT_MAX, true, 0);
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info current(0, 0, false, 0);
    current.size = left.size + right.size + 1;
    current.maxi = std::max(root->data, right.maxi);
    current.mini = std::min(root->data, left.mini);

    if (left.isbst && right.isbst && (root->data > left.maxi) && (root->data < right.mini)) {
        current.isbst = true;
    } else {
        current.isbst = false;
    }

    if (current.isbst) {
        ans = std::max(ans, current.size);
    }

    return current;
}

// Function to find the size of the largest BST in a binary tree
int largestBST(TreeNode *root) {
    int maxsize = 0;
    solve(root, maxsize);
    return maxsize;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    // Find the size of the largest BST in the binary tree
    int result = largestBST(root);

    // Print the result
    std::cout << "Size of the largest BST is: " << result << std::endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
