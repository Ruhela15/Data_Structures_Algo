#include<iostream>
#include<vector>
class Node{
    public:
    int data;
    Node*next ;
    Node(int data1 ,Node*next1 = nullptr){
        data = data1;
        next =next1;
    }

};

using namespace std;
Node detct (Node*head){
    Node*slow = head;
    Node*fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
int main(){

}