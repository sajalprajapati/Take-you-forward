#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

node *createSinglyLinkedList() {
    int number_of_nodes;
    cout << "\n Enter the number of nodes" << endl;
    cin >> number_of_nodes;

    node *head = nullptr;
    node *tail = nullptr;
    for (int i = 0; i < number_of_nodes; i++) {
        int data;
        cout << "\n Enter the data for the " << i + 1 << "-th node";
        cin >> data;

        node *newnode = new node(data);
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

node *sortedInsertion(node *head, int target) {
    node *newnode = new node(target);
    if (head == nullptr) {
        head = newnode;
        return head;
    }
    if (head->data >= target) {
        newnode->next = head;
        head = newnode;
        return head;
    }

    node *previous = nullptr;
    node *current = head;

    while ( current->data < target) {
        previous = current;
        current = current->next;
    }

    
        previous->next = newnode;
        newnode->next = current;
    

    return head;   
}

void traversal(node *head) {
    node *current = head;
    while (current != nullptr) {
        cout << current->data << " <-";
        current = current->next;
    }
    cout << " NULL" << endl;
}

int main() {
    node *root = createSinglyLinkedList();
    cout << "\n The linked list before the insertion is ";
    traversal(root);

    int target;
    cout << "\n Enter the target";
    cin >> target;
    root = sortedInsertion(root, target);
    cout << "\n The linked list after the insertion is " << endl;
    traversal(root);
}