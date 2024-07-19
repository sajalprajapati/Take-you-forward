#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

bool detectLoop(Node* head) {
    Node* slow_p = head;
    Node* fast_p = head;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}

int main() {
    // Creating a linked list with a loop for demonstration
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    if (detectLoop(head)) {
        cout << "Loop detected" << endl;
    } else {
        cout << "No loop detected" << endl;
    }

    return 0;
}
