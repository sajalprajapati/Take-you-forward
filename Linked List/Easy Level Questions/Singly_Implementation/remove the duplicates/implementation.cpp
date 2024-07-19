#include <bits/stdc++.h>
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

node* CreateLinkedList() {
    int number_of_node;
    cout << "\nTell me how many nodes of singly linked list we want to create now" << endl;
    cin >> number_of_node;

    node* head = nullptr;
    node* tail = nullptr;

    for (int i = 0; i < number_of_node; i++) {
        int data;
        cout << "\nWhat data do we want to insert in the node" << endl;
        cin >> data;

        node* newnode = new node(data); // Dynamically creating the node and storing it in memory

        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    return head;
}

void traversingSinglyList(node* head) {
    node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "NULL" << endl; // Ensure to print NULL at the end of the list
}

node* removeDuplicates(node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    node* root = CreateLinkedList();

    // Print the original linked list
    cout << "Original list: ";
    traversingSinglyList(root);

    // Remove duplicates from the linked list
    node* remove_root = removeDuplicates(root);

    // Print the linked list after removing duplicates
    cout << "List after removing duplicates: ";
    traversingSinglyList(remove_root);

    return 0;
}
