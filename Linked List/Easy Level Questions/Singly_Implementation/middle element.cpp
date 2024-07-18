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


int middleElement(node *head)
{
    if(head==nullptr)
    {
        return 0;
    }
    node *slow=head;
    node *fast=head;

    while(fast!=nullptr and fast->next!=nullptr)// the condition for fast!=nullptr is for the odd size and fast->next!=nullptr
    {
        slow=slow->next; //it is a tortoise ..which moves very slowly..
        fast=fast->next->next;
    }

    return slow->data;
}
int main()
{
    node *root=CreateLinkedList();
   
    int answer=middleElement(root);
    if(answer==0)
    {
        cout<<"\n linked list is empty"<<endl;
    }
    else
    {
        cout<<"\n the middle element is "<<answer<<endl;
    }
}