#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*back;
    Node(int data1,Node*next1=nullptr,Node*back1 =nullptr){
        data  = data1;
        next = next1;
        back = back1;
    }
};
Node*convert(vector<int>arr){
    Node*head = new Node(arr[0]);
    Node*prev = head;
    for(int i = 1; i<arr.size();i++){
        Node*temp = new Node(arr[i],nullptr,prev);
        prev->next = temp ;
        prev = temp;
    }
    return head;
}
void  print(Node*head){
    while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
    }
}
Node*deleteHead(Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node*prev = head;
    head = head->next;
  head->back = nullptr;
  prev->back =  nullptr;
  delete prev;
  return head;
}
Node*removetail(Node*head){
 if(head ==NULL||head->next==NULL){
    return NULL;
 }
 Node*tail = head;
 while(tail->next!=NULL){
    tail = tail->next;
 }
 Node*prev = tail->back;
 prev->next = nullptr;
 tail->back = nullptr;
 delete tail;
 return head;
}
Node*remove(Node*head,int k){
    if(head==NULL){
        return NULL;
    }
    Node*kthnode = head;
    int cnt = 0;
    while(kthnode!=NULL){
        cnt++;
        if(cnt==k) break;
        kthnode = kthnode->next;
    }
    Node*prev = kthnode->back;
    Node*front = kthnode->next;
    if(prev==NULL||front==NULL){
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return removetail(head);
    }
    prev->next = front;
    front ->back  = prev;
    delete kthnode;
    return head;
}
int main(){
    vector<int>arr = {12,22,33,34,45};
    Node*head = convert(arr);
    head = remove(head,3);
    print(head);
}