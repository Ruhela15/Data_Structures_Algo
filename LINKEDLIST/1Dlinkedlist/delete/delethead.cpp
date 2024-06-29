#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data ;
Node*next;
Node(int data1,Node*next1=nullptr){
     data = data1;
     next = next1;
}
};
Node*convertarr2ll(vector<int>arr){
    Node*head = new Node(arr[0]);
    Node*mover = head;
    for(int i  = 1; i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp ;
    }
    return head;
}
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
} 
 
 Node*remove(Node*head){
    if(head==NULL)return head;
    Node*temp = head;
    head = head->next;
    delete temp;
    return head;
 }

int main(){
    vector<int>arr = {12,23,34,55,56};
    Node *head = convertarr2ll(arr);
    head = remove(head);
    print(head);
}