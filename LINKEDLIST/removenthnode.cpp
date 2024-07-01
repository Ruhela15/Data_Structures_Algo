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

Node *remove(Node *head, int k)
{
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < k; i++)
    {
        if (fast == nullptr)
            return head;
        fast = fast->next;
    }

    if (fast == nullptr)
        return head->next;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *deletenode = slow->next;
    slow->next = slow->next->next;
    delete deletenode;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convert(arr);
    head = remove(head, 5);
    print(head);
    return 0;
}
