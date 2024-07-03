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

Node *convert(const vector<int> &arr)
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

Node *middle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *slow = head;
    Node *fast = head;
    fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow->next;
    middle = slow->next->next;
    delete middle;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 7, 8};
    Node *head = convert(arr);
    head = middle(head);
    print(head);
    return 0;
}
