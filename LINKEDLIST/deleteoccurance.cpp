#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node *convert(const vector<int> &arr) {
    if (arr.empty()) return nullptr;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
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

Node *occurance(Node *head, int k) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == k) {
            Node *nextnode = temp->next;
            Node *prevnode = temp->back;
            if (temp == head) {
                head = nextnode;
                if (head != nullptr) {
                    head->back = nullptr;
                }
            } else {
                if (nextnode != nullptr) {
                    nextnode->back = prevnode;
                }
                if (prevnode != nullptr) {
                    prevnode->next = nextnode;
                }
            }
            Node *nodeToDelete = temp;
            temp = nextnode;
            delete nodeToDelete;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    vector<int> arr = {4, 10, 2, 10, 2, 10, 3, 10, 45};
    Node *head = convert(arr);
    head = occurance(head, 10);
    print(head);
    return 0;
}
