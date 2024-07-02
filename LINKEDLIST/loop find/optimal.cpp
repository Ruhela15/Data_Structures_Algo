#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};
Node *convert(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
}
void print(Node*head){
    while(head!=NULL){

    
    cout<<head->data<<" ";
    head = head->next;
}
}
bool detectCycle(Node *head)
{
	Node*slow = head;
    Node*fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;

    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 3, 5, 7, 8};
    Node *head = convert(arr);
     if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    if(detectCycle)
    print(head);
}