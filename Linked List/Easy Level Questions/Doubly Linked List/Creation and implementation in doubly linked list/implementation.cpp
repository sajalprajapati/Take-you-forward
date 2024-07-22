#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* previous;

    node(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->previous=nullptr;
    }
};

node* createDoublyLinkedList()
{
    int numberOfNodes;
    cout<<"\n enter the number of nodes want to create"<<endl;
    cin>>numberOfNodes;

    if(numberOfNodes<=0)
    {
        cout<<"\n no creation of the linked list as the number of nodes is zero"<<endl;
        return nullptr;
    }

   node* head=nullptr;
   node* tail=nullptr;
   for(int i=0;i<numberOfNodes;i++)
   {
     int data;
     cout<<"\n enter the data for the node -"<<i;
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
        newnode->previous=tail;
        tail=newnode;
     }
   }

   return head;
}


void traversal(node *head)
{
    if(head==nullptr)
    {
        return;
    }

    cout<<head->data<<" ";
    traversal(head->next);
}


int main()
{
    node* root=createDoublyLinkedList();
    traversal(root);
}