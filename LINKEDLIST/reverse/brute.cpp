#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data ;
 Node*next;
 Node*back;
 Node(int data1,Node*next1 = nullptr,Node*back1 = nullptr){
   data = data1;
   next = next1;
   back = back1;
 }
};
Node*convert(vector<int>arr){
    Node*head  = new Node(arr[0]);
    Node*prev = head;
    for(int i = 1; i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        prev->next = temp;
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
  
  Node*reverse(Node*head){
    if(head==NULL||head->next==NULL) return head;
    Node*temp = head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp !=NULL){
       temp->data = st.top();
     st.pop();
     temp = temp->next;
    }
       return head;
  }
int main(){
 vector<int>arr = {1,2,3,4,5,6};
 Node*head = convert(arr);
 head = reverse(head);
 print (head);
} 