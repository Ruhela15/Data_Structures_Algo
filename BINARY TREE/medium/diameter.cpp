#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left=right=nullptr;
    }
};
class sol{
public:
int diametertree(Node*root){
    int daimeter = 0;
    height(root,daimeter);
    return daimeter;
}
private:
int height(Node*node,int&diameter){
    if(!node) return 0;
    int lh = height(node->left,diameter);
    int rh = height(node->right,diameter);
    diameter = max(diameter,lh+rh);
    return 1+max(lh,rh);
}
};
int main(){
        Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    sol Sol;
    int diameter = Sol.diametertree(root);
    cout<<diameter<<endl;
}

