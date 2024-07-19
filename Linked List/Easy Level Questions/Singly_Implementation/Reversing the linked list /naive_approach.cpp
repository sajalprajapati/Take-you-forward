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

node* reverse(node* head) {
    if (head == nullptr)
        return head;

    stack<int> st;

    node* current = head;
    while (current != nullptr) {
        st.push(current->data);
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        current->data = st.top();
        st.pop();
        current = current->next;
    }

    return head;
}

int main() {
    node* root = CreateLinkedList();

    // Print the original linked list
    cout << "Original list: ";
    traversingSinglyList(root);

    // Reverse the linked list
    node* reverse_head = reverse(root);

    // Print the reversed linked list
    cout << "Reversed list: ";
    traversingSinglyList(reverse_head);

    return 0;
}
