#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        int cur = root->val;
        if (cur < p->val && cur < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (cur > p->val && cur > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

// Function to insert nodes in the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

int main() {
    Solution sol;

    // Constructing the BST
    TreeNode* root = new TreeNode(6);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 3);
    root = insert(root, 5);

    // Example nodes
    TreeNode* p = root->left;  // Node with value 2
    TreeNode* q = root->left->right;  // Node with value 4

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        std::cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << std::endl;
    } else {
        std::cout << "LCA does not exist." << std::endl;
    }

    return 0;
}
