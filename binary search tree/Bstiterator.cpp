#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Sol {
public:
    vector<Node*> Nodes;
    int start = 0;

    void inorder(Node* root, vector<Node*>& Nodes) {
        if (root == nullptr) return;
        inorder(root->left, Nodes);
        Nodes.push_back(root);
        inorder(root->right, Nodes);
    }

    void bst(Node* root) {
        inorder(root, Nodes);
    }

    int next() {
        int x = Nodes[start]->data;
        start++;
        return x;
    }

    bool hasNext() {
        return start < Nodes.size();
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Sol sol;
    sol.bst(root);

    while (sol.hasNext()) {
        cout << sol.next() << " ";
    }

    return 0;
}
