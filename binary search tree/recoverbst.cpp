#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val)) {
            if (first == NULL) {
                first  = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};

void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create a binary tree with swapped nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Original tree in-order: ";
    printInOrder(root);
    cout << endl;

    // Recover the BST
    Solution sol;
    sol.recoverTree(root);

    // Print the recovered BST
    cout << "Recovered tree in-order: ";
    printInOrder(root);
    cout << endl;

    // Clean up the allocated memory
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
