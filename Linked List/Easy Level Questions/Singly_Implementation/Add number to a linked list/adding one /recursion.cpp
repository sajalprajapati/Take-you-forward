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

int helper(node* head) 
{
   if(head==nullptr)
   return 1;

   int carry = helper(head->next);

   head->data=head->data+carry;

   if(head->data>10)
   {
    head->data=0;
    return 1;
   }

    else
    {
        return 0;
    }
}

node* addingOneTotheLinkedList(node* head) 
{
  //here we will be applying backtracking and recursion...
  node* finalcarry=helper(head);

  if(finalcarry==1)
  {
    node* newnode=new node(finalcarry);
    newnode->next=head;
    return newnode;
  }

  return head;    
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
