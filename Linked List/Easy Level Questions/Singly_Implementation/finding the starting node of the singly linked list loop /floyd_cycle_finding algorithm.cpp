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

Node* detectLoop(Node* head) 
{
    if (head == nullptr) {
        return nullptr;
    }

    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Starting point of the loop
        }
    }

    return nullptr; // No loop found
}

int main() {
    // Creating a linked list with a loop for demonstration
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    Node* answer = detectLoop(head);
    if (answer) {
        cout << "Loop detected at node with data: " << answer->data << endl;
    } else {
        cout << "No loop detected" << endl;
    }

    return 0;
}
