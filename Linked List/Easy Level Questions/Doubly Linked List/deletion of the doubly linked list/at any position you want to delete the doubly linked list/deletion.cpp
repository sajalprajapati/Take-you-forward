#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

node* createDoublyLinkedList() {
    int numberOfNodes;
    cout << "\nEnter the number of nodes you want to create: ";
    cin >> numberOfNodes;

    if (numberOfNodes <= 0) {
        cout << "\nNo creation of the linked list as the number of nodes is zero or negative" << endl;
        return nullptr;
    }

    node* head = nullptr;
    node* tail = nullptr;
    for (int i = 0; i < numberOfNodes; i++) {
        int data;
        cout << "Enter the data for the node " << i + 1 << ": ";
        cin >> data;

        node* newNode = new node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void traversal(node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

node* deleteDoublyLinkedList(node* head, int position) {
    // Base case
    if (head == nullptr) {
        return nullptr;
    }

    node* current = head;

    // Deleting the head node
    if(position<=0)
    {
        cout<<"\n linked list ke starting node se pehle kuch hota hai kya bhai...toh hum kaise delete kar denge..."<<endl;
        return head;
    }
    
    if (position == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete current;
        return head;
    }

    // Traverse to the node to be deleted
    for (int i = 1; current != nullptr && i < position; i++) {
        current = current->next;
    }

    // If position is more than the number of nodes
    if (current == nullptr) {
        cout << "Position is greater than the number of nodes in the list" << endl;
        return head;
    }

    // Deleting the node
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }

    delete current;

    return head;
}

int main() {
    node* root = createDoublyLinkedList();
    cout << "Original Doubly Linked List: ";
    traversal(root);

    int position;
    cout << "\nEnter the position of the node you want to delete: ";
    cin >> position;

    root = deleteDoublyLinkedList(root, position);

    cout << "Doubly Linked List after deletion: ";
    traversal(root);

    return 0;
}
