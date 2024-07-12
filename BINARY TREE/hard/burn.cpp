#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* result = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                result = front;
            }

            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
    }

    int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
        map<Node*, bool> vis;
        queue<Node*> q;
        q.push(root);
        vis[root] = true;
        int ans = 0;

        while (!q.empty()) {
            bool flag = false;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left && !vis[front->left]) {
                    flag = true;
                    q.push(front->left);
                    vis[front->left] = true;
                }

                if (front->right && !vis[front->right]) {
                    flag = true;
                    q.push(front->right);
                    vis[front->right] = true;
                }

                if (nodeToParent[front] && !vis[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    vis[nodeToParent[front]] = true;
                }
            }

            if (flag) {
                ans++;
            }
        }
        return ans;
    }

    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};
