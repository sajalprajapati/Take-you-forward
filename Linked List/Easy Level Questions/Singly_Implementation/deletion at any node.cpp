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


node* createSinglyLinkedList()
{
    int number_of_nodes;
    cout<<"\n enter the number of nodes"<<endl;
    cin>>number_of_nodes;

    node *head=nullptr;
    node *tail=nullptr;
    for(int i=0;i<number_of_nodes;i++)
    {
        int data;
        cout<<"\n enter the number of nodes"<<endl;
        cin>>data;

        node* newnode=new node(data);
 
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


node* deletionOfTheLinkedList(node *head,int position)
{
    if(head==nullptr)
    {
        return head;
    }

    node *dummy=new node(0);
    dummy->next=head;

    int i=0;
    node *previous=nullptr;
    node *current=dummy;

    while(i<position)
    {
      previous=current;
      current=current->next;
      i++; 
    }

    previous->next=current->next;
    delete(current);
    if(i==1 and position==1)
    head=previous->next;


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


int main()
{
    node *root=createSinglyLinkedList();
    cout<<"\n the linked list before the deletion is "<<endl;
    traversingSinglyList(root);

    int position;
    cout<<"\n at which position you want to delete the element "<<endl;
    cin>>position;

    root=deletionOfTheLinkedList(root,position);
    cout<<"\n the linked list after the deletion is "<<endl;
    traversingSinglyList(root);
}