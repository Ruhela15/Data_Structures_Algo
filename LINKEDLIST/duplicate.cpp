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

Node * removeDuplicates(Node *head) {
    if (!head) return nullptr;
    unordered_set<int> seen;
    Node *current = head;
    while (current) {
        if (seen.find(current->data) != seen.end()) {
            Node *duplicate = current;
            if (current->back) {
                current->back->next = current->next;
            }
            if (current->next) {
                current->next->back = current->back;
            }
            current = current->next;
            delete duplicate;
        } else {
            seen.insert(current->data);
            current = current->next;
        }
    }
    return head;
}

int main() {
    vector<int> arr = {4, 10, 2, 10, 2, 10, 3, 10, 45};
    Node *head = convert(arr);
    head = removeDuplicates(head);
    print(head);
    return 0;
}
