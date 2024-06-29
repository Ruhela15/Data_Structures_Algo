#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node *convert(vector<int> arr) {
    if (arr.empty()) return nullptr;  
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insert(Node *head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node *newnode = new Node(val);
    temp->next = newnode;
    return head;
}

int main() {
    vector<int> arr = {12, 23, 34, 45, 56};
    Node *head = convert(arr);
    head = insert(head, 15);
    print(head);
    return 0;
}
