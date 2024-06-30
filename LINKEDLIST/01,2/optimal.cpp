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
Node *arrange(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1, 2, 0, 2, 1, 2, 2, 0};
    Node *head = convert(arr);
    head = arrange(head);

    print(head);
}