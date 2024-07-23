#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* previous;

    node(int data) {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

vector<pair<int, int>> FindingtheSum(node* head, int target) {
    vector<pair<int, int>> pairs;

    if (head == nullptr) {
        return pairs; // Return empty vector if head is nullptr
    }

    if (head->next == nullptr) {
        if (head->data == target) {
            pairs.push_back(make_pair(head->data, 0));
        }
        return pairs; // Return pairs even if it's empty
    }

    node* temp1 = head;
    while (temp1 != nullptr) {
        node* temp2 = temp1->next; // Initialize temp2 properly
        while (temp2 != nullptr) {
            if (temp1->data + temp2->data == target) {
                pairs.push_back(make_pair(temp1->data, temp2->data));
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return pairs;
}

// Helper function to create a doubly linked list for testing
node* createDoublyLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    node* head = new node(values[0]);
    node* tail = head;
    for (size_t i = 1; i < values.size(); ++i) {
        node* newNode = new node(values[i]);
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    return head;
}

// Helper function to traverse and print the doubly linked list
void traversal(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {5, 3, 4, 2, 7, 8, 1};
    node* root = createDoublyLinkedList(values);

    cout << "Original list: ";
    traversal(root);

    int target = 9;
    vector<pair<int, int>> pairs = FindingtheSum(root, target);

    cout << "Pairs with sum " << target << ": ";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
