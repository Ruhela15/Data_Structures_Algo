#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data1,Node*next1 = nullptr){
        data = data1;
        next = next1;
    }
};
 Node*convert(vector<int>arr){
    Node*head = new Node(arr[0]);
    Node*mover = head;
    for(int i = 1; i<arr.size();i++){
        Node* temp  = new Node(arr[i]);
        mover->next = temp ;
        mover  = temp;
    }
    return head;
 }
 void print(Node*head){
    while(head!=NULL){
       cout<< head->data<<" ";
       head = head->next;
    }
 }
 Node*removek(Node*head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    } 
    int cnt = 0;
    Node*temp = head ;
    Node*prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
 }
int main(){
    vector<int>arr = {12,33,45,56,67};
    Node*head = convert(arr);
    head = removek(head,3);
    print(head);
}
