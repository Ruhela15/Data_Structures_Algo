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
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *oddeven(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    temp = head;
    temp = head->next;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    int i = 0;
    temp = head;
    while (temp != NULL)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convert(arr);
    head = oddeven(head);
    print(head);
}