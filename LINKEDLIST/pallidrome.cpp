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
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
bool pallidrome(Node*head){
    Node*temp  = head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 3, 2, 1};
    Node *head = convert(arr);
       if (pallidrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}