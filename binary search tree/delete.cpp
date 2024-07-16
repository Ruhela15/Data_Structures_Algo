#include <iostream>
using namespace std;

/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(nullptr), right(nullptr) {}
        BinaryTreeNode(T x) : data(x), left(nullptr), right(nullptr) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x) : data(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

BinaryTreeNode<int>* minval(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->data == key) {
        if (root->left == nullptr) {
            BinaryTreeNode<int>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BinaryTreeNode<int>* temp = root->left;
            delete root;
            return temp;
        }

        BinaryTreeNode<int>* temp = minval(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    } else if (root->data > key) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }

    return root;
}

void inorderTraversal(BinaryTreeNode<int>* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(50);
    root->left = new BinaryTreeNode<int>(30);
    root->right = new BinaryTreeNode<int>(70);
    root->left->left = new BinaryTreeNode<int>(20);
    root->left->right = new BinaryTreeNode<int>(40);
    root->right->left = new BinaryTreeNode<int>(60);
    root->right->right = new BinaryTreeNode<int>(80);

    cout << "Inorder traversal of the original tree: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node with value 20
    root = deleteNode(root, 20);
    cout << "Inorder traversal after deleting 20: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node with value 30
    root = deleteNode(root, 30);
    cout << "Inorder traversal after deleting 30: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node with value 50
    root = deleteNode(root, 50);
    cout << "Inorder traversal after deleting 50: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
