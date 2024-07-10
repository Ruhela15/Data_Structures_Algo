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
bool isleaf(Node*root){
    return !root->left&&!root->right;
}
void addleftboundary(Node*root,vector<int>&res){
    Node*cur = root->left;
    while(cur){
        if(!isleaf(cur)) res.push_back(cur->data);
        if(cur->left) cur= cur->left;
        else cur = cur->right;
    }
}
void addrightboundary(Node*root,vector<int>&res){
    Node*cur = root->right;
    vector<int>temp;
    while(cur){
        if(!isleaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i = temp.size()-1;i>=0;--i){
        res.push_back(temp[i]);
    }
}
void addleaf(Node*root,vector<int>&res){
    if(isleaf(root)){
        res.push_back(root->data);
    }
    if(root->left) addleaf(root->left,res);
    if(root->right) addleaf(root->right,res);
}
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        if (!isleaf(root)) {
            res.push_back(root->data);
        }

        // Add the left boundary, leaves,
        // and right boundary in order
        addleftboundary(root, res);
        addleaf(root, res);
        addrightboundary(root, res);

        return res;
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
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}