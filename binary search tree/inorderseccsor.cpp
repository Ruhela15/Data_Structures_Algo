#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* bstsuccessor(Node* root, Node* p) {
    Node* successor = NULL;
    while (root != NULL) {
        if (p->data >= root->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main() {
    // Constructing the BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    Node* p = root->left;  // Node with value 10

    Node* succ = bstsuccessor(root, p);
    if (succ != NULL) {
        cout << "Inorder Successor of " << p->data << " is " << succ->data << endl;
    } else {
        cout << "Inorder Successor of " << p->data << " does not exist." << endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
