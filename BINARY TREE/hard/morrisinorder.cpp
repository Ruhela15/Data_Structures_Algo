#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> inorderM(Node* root) {
    vector<int> inorder;
    Node* cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) {
            inorder.push_back(cur->data);
            cur = cur->right;
        } else {
            Node* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right = new Node(6); // This line should be removed as it overwrites the previous line

    vector<int> result = inorderM(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
