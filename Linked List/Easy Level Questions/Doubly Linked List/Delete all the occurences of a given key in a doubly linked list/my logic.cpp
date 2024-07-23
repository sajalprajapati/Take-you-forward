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
    cout<<"enter the number of nodes want to create"<<endl;
    cin>>numberOfNodes;

    if(numberOfNodes<=0)
    {
        cout<<"no creation of the linked list as the number of nodes is zero"<<endl;
        return nullptr;
    }

   node* head=nullptr;
   node* tail=nullptr;
   for(int i=0;i<numberOfNodes;i++)
   {
     int data;
     cout<<"enter the data for the node -"<<i<<":";
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

node* deletionAllOccurrences(node* head,int key)
{
    if(head==nullptr)
    return nullptr;

    if(head->next==nullptr and key==head->data)
    {
        delete(head);
        return nullptr;
    }
    

    node* current=head;
    node* prev=nullptr;
    while(current!=nullptr)
    {
        if(current->data==key)
        {
            if(current->previous==nullptr)//it means I am at the first node
            {
             head=head->next;
             prev=current;
             current=current->next;
             current->previous=nullptr;
             prev->next=nullptr;  
            }

            else if(current->next==nullptr)//it means we are at the ending node
            {
                current->previous->next=current->next;
                current->previous=nullptr;
                delete(current);
                current=nullptr;
            }
            else
            {
                current->next->previous=current->previous;
                current->previous->next=current->next;
                prev=current;
                current=current->next;
                delete(prev);
            }
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
    node* root=createDoublyLinkedList();
    int key;
    cout<<" enter the value  of key"<<endl;
    cin>>key;
    traversal(deletionAllOccurrences(root,key));
}