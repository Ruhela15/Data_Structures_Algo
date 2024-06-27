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

// Function to convert a vector to a linked list
Node* convertArrToLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;  // Handle empty array

    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (size_t i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Function to calculate the length of the linked list and print its elements
int length(Node *head) {
    int cnt = 0;
    Node *temp = head;
    while (temp) {
        temp = temp->next;
        cnt++;
    }
    cout << endl;
    return cnt;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    Node *head = convertArrToLL(arr);
    int len = length(head);
    cout << "Length of the linked list: " << len << endl;
    return 0;
}
