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
vector<int>vertical(Node*root){
    vector<int>ans;
    if(root==NULL) return ans;
    map<int,map<int,vector<int>>>nodes;
    queue<pair<Node*,pair<int,int>>>q;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node*,pair<int,int>>temp = q.front();
        q.pop();
        Node*frontnode = temp.first;
        int hd  = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(frontnode->data);
        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
        }

    }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                     ans.push_back(k);
                }
            }
        }
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
    vector<int> result = solution.vertical(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}