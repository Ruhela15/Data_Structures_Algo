#include<bits/stdc++.h>
using namespace std; 
class Node{
 public:
 int data ;
 Node*next;
 Node(int data1,Node*next1 = nullptr){
    data = data1;
    next = next1;
 }
};
Node*convert(vector<int>arr){
    Node*head  = new Node(arr[0]);
    Node*mover = head;
    for(int i = 1; i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node*head){
    while(head!=NULL){
       cout<<head->data<<" ";
       head = head->next;
    }
}
Node*insert(Node*head,int val){
    Node*temp = new Node(val,head);
    return temp;
}
int main(){
    vector<int>arr = {12,23,34,45,56};
    Node*head = convert(arr);
    head  = insert(head,15);
    print (head);
}