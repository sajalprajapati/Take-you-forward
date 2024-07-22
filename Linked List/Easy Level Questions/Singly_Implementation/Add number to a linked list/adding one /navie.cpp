#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

node* createSinglyLinkedList() {
    int number_of_nodes;
    cout << "\nEnter the number of nodes: ";
    cin >> number_of_nodes;

    node* head = nullptr;
    node* tail = nullptr;
    for(int i = 0; i < number_of_nodes; i++) {
        int data;
        cout << "\nEnter the data for node " << i << ": ";
        cin >> data;

        node* newnode = new node(data);
        if(head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    return head;
}

node* reversal(node* head) {
    node* current = head;
    node* previous = nullptr;
    while(current != nullptr) {
        node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

node* addingOneTotheLinkedList(node* head) {
    // Step 1: Reverse the linked list
    head = reversal(head);

    node* current = head;
    int carry = 1;

    while(current != nullptr) {
        current->data = current->data + carry;

        if(current->data < 10) {
            carry = 0;
            break;
        } else if(current->data >= 10) {
            current->data = 0;
            carry = 1;
        }

        if(current->next == nullptr && carry == 1) {
            current->next = new node(carry);
            carry = 0;
        }

        current = current->next;
    }

    // Step 2: Reverse the linked list again to restore original order
    return reversal(head);
}

void traverseLinkedList(node* head) {
    node* current = head;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    node* head = createSinglyLinkedList();
    cout << "Original Linked List: ";
    traverseLinkedList(head);

    head = addingOneTotheLinkedList(head);
    cout << "Linked List after adding one: ";
    traverseLinkedList(head);

    return 0;
}
