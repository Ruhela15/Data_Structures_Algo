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
int maxsum(Node*root){
    int maxi = INT_MIN;
    maxsumpath(root,maxi);
    return maxi;
}
private:
int maxsumpath(Node*node,int&maxi){
    if(!node) return 0;
    int lh = max(0,maxsumpath(node->left,maxi));
    int rh = max(0,maxsumpath(node->right,maxi));
    maxi = max(maxi,lh+rh,node->data);
    return max(lh,rh)+node->data;
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
    int maxsum = Sol.maxsum(root);
    cout<<maxsum<<endl;
}