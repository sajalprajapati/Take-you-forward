#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

node* CreateLinkedList()
{
    int number_of_node;
    cout<<"\n tell me how many nodes of singly linked list we want to create ..now"<<endl;
    cin>>number_of_node;

   node* head=nullptr;
   node* tail=nullptr;

   for(int i=0;i<number_of_node;i++)
   {
    int data;
    cout<<"\n what data we want to insert in the node"<<endl;
    cin>>data;

    node* newnode=new node(data); //this is dynamically we are creating the node and storing it in the memory;

    if(head==nullptr)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
   }

   return head;
}

void traversingSinglyList(node *head)
{
    node* current=head;

    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }

    if(head==nullptr)
    {
        cout<<"NULL"<<endl;
    }
}

node* rotation(node* head,int k)
{
   if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    // Calculate the length of the linked list.
    node* tail = head;
    int length = 1;
    while (tail->next != nullptr) {
        length++;
        tail = tail->next;
    }

    // Connect the last node to the head to make it a circular linked list.
    tail->next = head;

    // If k is a multiple of the length of the list, no rotation is needed.
    k = k % length;
    if (k == 0) {
        tail->next = nullptr;  // Break the circular link before returning.
        return head;
    }

    // Find the new end of the list after the rotation.
    node* current = head;
    int stepsToNewEnd = length - k - 1; // stepsToNewEnd should point to the node just before the new head
    while (stepsToNewEnd--) {
        current = current->next;
    }

    // Set the new head and break the circular link.
    head = current->next;
    current->next = nullptr;

    return head;
}

int main()
{
    node *root=CreateLinkedList();

    //now we want to print the element from the linked list ..
    traversingSinglyList(rotation(root,10));
    
   
    return 0;
}