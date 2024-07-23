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

node* createSinglyLinkedList() {
    int number_of_nodes;
    cout << "\nEnter the number of nodes: " << endl;
    cin >> number_of_nodes;

    node* head = nullptr;
    node* tail = nullptr;
    for (int i = 0; i < number_of_nodes; i++) {
        int data;
        cout << "Enter the data for node " << i << ": ";
        cin >> data;

        node* newnode = new node(data);

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

node* adding_two_number(node* head1, node* head2) {
    if (head1 == nullptr)
        return head2;
    else if (head2 == nullptr)
        return head1;

    node* dummyNode = new node(-1);
    node* current = dummyNode;
    node* current1 = head1;
    node* current2 = head2;

    int carry = 0;
    while (current1 != nullptr || current2 != nullptr) {
        int sum = carry;

        if (current1) sum += current1->data;
        if (current2) sum += current2->data;

        node* newnode = new node(sum % 10);
        carry = sum / 10;
        current->next = newnode;
        current = newnode;

        if (current1) current1 = current1->next;
        if (current2) current2 = current2->next;
    }

    if (carry == 1) {
        node* newnode = new node(carry);
        current->next = newnode;
    }

    return dummyNode->next;
}

int main() {
    cout << "Create first linked list: " << endl;
    node* head1 = createSinglyLinkedList();

    cout << "Create second linked list: " << endl;
    node* head2 = createSinglyLinkedList();

    node* result = adding_two_number(head1, head2);
    cout << "Resultant linked list after adding the two numbers: ";
    while (result != nullptr) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
