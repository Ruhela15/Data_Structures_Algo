#include<bits/stdc++.h>
using namespace std;
struct Node
{
 int data ;
 Node*left;
 Node*right;
 Node(int val){
    data = val;
    left = right = nullptr;
 }
};
class solution{
 public:
 vector<int>preorder(Node*root){
vector<int>preOrder;
if(root==NULL) return preOrder;
stack<Node*>st;
st.push(root);
while(!st.empty()){
    root = st.top();
    st.pop();
    preOrder.push_back(root->data);
    if(root->left!=NULL){
        st.push(root->left);
    }
    if(root->right!=NULL){
        st.push(root->right);
    }
}
return preOrder;
 }

};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    solution sol;
    vector<int>result = sol.preorder(root);
     cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
}