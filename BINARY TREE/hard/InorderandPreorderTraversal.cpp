#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
};
Node*contruct(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&mpp){
    if(prestart>preend||instart>inend) return NULL;
    Node*root  = new Node(preorder[prestart]);
    int el = mpp[root->data];
    int numleft = el-instart;
    root->left = contruct(preorder,prestart+1,prestart+numleft,inorder,instart,el-1,mpp);
    root->right = contruct(preorder,prestart+numleft+1,preend,inorder,el+1,inend,mpp);
    return root;
}
Node*bulidtree(vector<int>&preorder,vector<int>&inorder){
    int prestart = 0;int preend  = preorder.size()-1;
    int instart = 0; int inend = inorder.size()-1;
    map<int,int>mpp;
    for(int i = 0;i<inorder.size();i++){
        mpp[inorder[i]] = i;
    }
    return contruct(preorder,prestart,preend,inorder,instart,inend,mpp);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    Node*root = bulidtree(preorder,inorder);

    return 0;
}
