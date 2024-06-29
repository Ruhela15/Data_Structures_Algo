#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node*next;
Node*back;
Node(int data1,Node*next1=nullptr,Node*back1 = nullptr){
    data = data1;
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
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
Node*insertH(Node*head,int val){
    if(head==NULL||head->next==NULL) return NULL;
    Node*temp = new Node(val,head);
    temp->back = nullptr;
    return temp;
}
 Node*insertkth(Node*head,int k,int val){
    if(k==1){
        return insertH(head,val);
    }
    Node*temp = head;
    int cnt = 0;
    while(temp!=NULL){
       cnt++;
       temp = temp->next;
       if(cnt==k) break;
    }
    Node*prev = temp->back;
    Node*newnode = new Node(val,temp,prev);
    prev->next = newnode;
    temp ->back = newnode;
    return head;
 }
int main(){
    vector<int>arr = {12,23,45,67};
     Node*head = convert(arr);
     head = insertkth(head,3,13);
     print (head);

}