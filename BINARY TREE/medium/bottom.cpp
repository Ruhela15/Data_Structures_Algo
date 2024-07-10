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
vector<int>top(Node*root){
    vector<int>ans;
    if(root==NULL) return ans;
    map<int,int>topnode;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node*frontnode = temp.first;
        int hd = temp.second;
            topnode[hd]  = frontnode->data;
        
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));

        }
          if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));

        }
    }
    for(auto i: topnode){
        ans.push_back(i.second);
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
    vector<int> result = solution.top(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}