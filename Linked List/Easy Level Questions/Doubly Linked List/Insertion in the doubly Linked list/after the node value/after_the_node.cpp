#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* previous;
    node* next;

    node(int data)
    {
        this->data=data;
        this->previous=nullptr;
        this->next=nullptr;
    }
};

node* createDoublyLinkedList()
{
    int number_of_nodes;
    cout<<"\n enter the number of nodes";
    cin>>number_of_nodes;

    node* head=nullptr;
    node* tail=nullptr;

    for(int i=0;i<number_of_nodes;i++)
    {
        int data;
        cout<<"\n enter the data for the-"<<i<<" node";
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

void tarversal(node* head)
{
    node* current=head;
    while(current!=nullptr)
    {
        cout<<current->data<<"-->";
        current=current->next;
    }

    cout<<"NULL"<<endl;
}

node* insertion(node* head,int position)
{
    if(position<=0)
    {
        cout<<"\n since the position is less than the size of the linked list .Therefore it is not possible to isnert node";
        return nullptr;
    }

    cout<<"\n enter the data for the node which is to be inserted ";
    int data;
    cin>>data;
    node* newnode=new node(data);

    if(head==nullptr)
    {
        return newnode;
    }

    node* current=head;
    int i=1;
   
   while(current!=nullptr and i<=position-1)
   {
     current=current->next;
     i++;
   }
    if(current==nullptr)
    {
        cout<<"\n the position number is greater than the size of the linked list";
        return head;
    }

     if (current->next == nullptr) {
        current->next = newnode;
        newnode->previous = current;
        return head;
    }

    newnode->next=current->next;
    current->next->previous=newnode;
    newnode->previous=current;
    current->next=newnode;

    return head;
}

int main()
{
    node* root=createDoublyLinkedList();
    int position;
    cout<<"\n enter the position";
    cin>>position;
    tarversal(insertion(root,position));
}

