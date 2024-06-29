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
 void element(Node*temp){
    Node*prev = temp->back;
    Node*front  = temp->next;
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    prev->next = front;
    front->back = prev;
    temp->back = temp->next;
    free(temp);
 }
int main(){
    vector<int>arr = {12,22,33,34,45};
    Node*head = convert(arr);
      element(head->next);
    print(head);
}