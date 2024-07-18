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

int SearchingSinglyList(node *head,int target)
{
    int count=0;
    if(head==nullptr)
    {
        return -1;
    }

    node *current=head;
    while(current!=nullptr)
    {
        count++;
        if(current->data==target)
        return count;
        else
        current=current->next;
    }

    return -1;
}

int main()
{
    node *root=CreateLinkedList();

    //now we want to search in the element from the linked list ..
    int target;
    cout<<"\n enter the number we want to search in the singly linked list "<<endl;
    cin>>target;

    int number= SearchingSinglyList(root,target);
    if(number!=-1)
    cout<<"\n the number is found at the number"<<number<<endl;
    else
    cout<<"\n the number is not found "<<endl;
    
   
    return 0;
}