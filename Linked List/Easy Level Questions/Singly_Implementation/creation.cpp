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


int main()
{
    node *root=CreateLinkedList();
    cout<<"\n this is being written oonce the operation is successful"<<endl;
    return 0;
}