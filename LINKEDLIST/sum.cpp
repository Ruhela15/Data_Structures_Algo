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

Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;
    if (head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head);

    while (left != right && left->back != right) {
        int sum = left->data + right->data;
        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        } else if (sum < k) {
            left = left->next;
        } else {
            right = right->back;
        }
    }

    return ans;
}

void printPairs(const vector<pair<int, int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
}

int main() {
    vector<int> arr = {4, 10, 2, 10, 2, 10, 3, 10, 45};
    Node *head = convert(arr);
    vector<pair<int, int>> pairs = findPairs(head, 12); // Example to find pairs that sum to 12
    printPairs(pairs);

    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
