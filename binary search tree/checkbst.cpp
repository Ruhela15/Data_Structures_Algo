#include<bits/stdc++.h>
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
public:
bool check(TreeNode*root,long long min,long long max){
    if(root==nullptr) return true;
    if(root->val>=max||root->val<=min) return false;
    return  check(root->left,min,root->val)&&
    check(root->right,root->val,max);
}
    bool isValidBST(TreeNode* root) {
        long long int min = -100000000000000;
        long long max = 1000000000000;
        return check(root,min,max);
    }
};