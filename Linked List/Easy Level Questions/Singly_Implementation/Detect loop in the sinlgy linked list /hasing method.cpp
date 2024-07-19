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
    unordered_set<Node*> seen; // Use unordered_set for storing the nodes

    while (head != nullptr) {
        // If this node is already present in the set, it means there is a cycle
        if (seen.find(head) != seen.end()) {
            return true;
        }
        // If we are seeing the node for the first time, insert it into the set
        seen.insert(head);
        head = head->next;
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
