#include <bits/stdc++.h>
using namespace std;

/*
    Following is the class structure of BinaryTreeNode class for reference:

    template <typename T>
    class BinaryTreeNode {
    public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
                delete left;
            }
            if (right) {
                delete right;
            }
        }
    };
*/

template <typename T>
class BinaryTreeNode {
public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

BinaryTreeNode<int>* build(vector<int>& preorder, int& i, int bound) {
    if (i == preorder.size() || preorder[i] > bound) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

// Function to print the tree in order for testing
void printInOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    BinaryTreeNode<int>* root = preorderToBST(preorder);

    // Print the tree in order to verify
    printInOrder(root);

    // Clean up the tree
    delete root;

    return 0;
}
