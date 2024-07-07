#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class solution
{
public:
    vector<vector<int>> levelorder(Node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *treenode = q.front();
                q.pop();
                level.push_back(treenode->data);
                if (treenode->left != NULL)
                {
                    q.push(treenode->left);
                }
                if(treenode->right!=NULL){
                    q.push(treenode->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
void printVector(const vector<int>& vec) {
  
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
     Node*root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left  = new Node(6);
root->right->right = new Node(7);
 solution Solution; 
    // Perform level-order traversal
    vector<vector<int>> result = Solution.levelorder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    // Printing the level order traversal result
    for (const vector<int>& level : result) {
        printVector(level);
    }
}