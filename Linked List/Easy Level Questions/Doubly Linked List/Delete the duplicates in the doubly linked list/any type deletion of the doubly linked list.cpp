#include <bits/stdc++.h>
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
            newNode->previous = tail;
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

node* deleteDoublyLinkedList(node* head) 
{
  if(head==nullptr or head->next==nullptr)
  return head;

  node* current=head;
  while(current!=nullptr and current->next!=nullptr)
  {
    if(current->data==current->next->data)
    {
     node* temp=current->next;
     current->next=temp->next;
     if(temp->next!=nullptr)
     {
        temp->next->previous=current;
     }

     delete(temp);
    }
    else
    {
        current=current->next;
    }
  }
  return head;  
}

int main() 
{
    node* root = createDoublyLinkedList();
    traversal( deleteDoublyLinkedList(root));
    return 0;
}
