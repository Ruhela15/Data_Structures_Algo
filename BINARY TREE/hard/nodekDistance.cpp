#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_set<TreeNode*> vis;

    // Function to map each node to its parent
    void connectwithparents(TreeNode* root, TreeNode* parent) {
        if (root == NULL) return;
        mp[root] = parent;
        connectwithparents(root->left, root);
        connectwithparents(root->right, root);
    }

    // DFS function to find nodes at distance k
    void dfs(TreeNode* target, int k, vector<int>& res) {
        if (target == NULL) return;
        if (vis.count(target)) return;
        vis.insert(target);
        if (k == 0) {
            res.push_back(target->val);
            return;
        }
        dfs(target->left, k - 1, res);
        dfs(target->right, k - 1, res);
        dfs(mp[target], k - 1, res);
    }

    // Function to return nodes at distance k from target
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if (root == NULL) return res;
        connectwithparents(root, NULL);
        dfs(target, k, res);
        return res;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* target = root->left; 
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    // Printing the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}