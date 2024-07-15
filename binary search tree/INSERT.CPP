#include <iostream>

// Node structure definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Solution class with the insert function
class Solution {
public:
    Node* insert(Node* node, int data) {
        if (node == nullptr) return new Node(data);

        Node* cur = node;
        while (true) {
            if (cur->data <= data) {
                if (cur->right != nullptr) {
                    cur = cur->right;
                } else {
                    cur->right = new Node(data);
                    break;
                }
            } else {
                if (cur->left != nullptr) {
                    cur = cur->left;
                } else {
                    cur->left = new Node(data);
                    break;
                }
            }
        }
        return node;
    }
};

// Helper function to print the tree in-order for testing purposes
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Solution solution;
    Node* root = nullptr;

    // Inserting nodes into the BST using the provided values
    int values[] = {82, 1, 106, 58, 89, 56, 68, 92, 24, 35, 26};
    for (int val : values) {
        root = solution.insert(root, val);
    }

    // Printing the in-order traversal of the BST
    std::cout << "In-order traversal of the BST: ";
    inorder(root);
    std::cout << std::endl;

    return 0;
}
