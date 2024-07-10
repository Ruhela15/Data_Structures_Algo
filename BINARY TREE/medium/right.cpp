#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node*left;
Node*right;
Node(int val){
    data  =val;
    left=right=nullptr;
}
};
class sol{
public:
void solve(Node*root,vector<int>&ans,int lvl){
    if(root==NULL) return ;
    if(lvl==ans.size()){
        ans.push_back(root->data);
        solve(root->right,ans,lvl+1);
                solve(root->left,ans,lvl+1);

    }
}
 vector<int>left(Node*root){
    vector<int>ans;
    solve(root,ans,0);
    return ans;
 }

};
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    sol solution;

    // Get the boundary traversal
    vector<int> result = solution.left(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}