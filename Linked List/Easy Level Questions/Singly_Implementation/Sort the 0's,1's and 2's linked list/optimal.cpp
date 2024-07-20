#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};


node* createSinglyLinkedList()
{
    int number_of_nodes;
    cout<<"\n enter the number of nodes "<<endl;
    cin>>number_of_nodes;

    node* head=nullptr;
    node* tail=nullptr;

    cout<<"\n only enter the 0's,1's and 2's value"<<endl;
    for(int i=0;i<number_of_nodes;i++)
    {
        int data;
        cout<<"\n enter the data for the node number -"<<i;
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

node* sortedLinkedList(node* head)
{
    if(head==nullptr or head->next==nullptr)
    return head;

   //we are creating dummy nodes;
   node* zeroHead=new node(10);
   node* oneHead=new node(10);
   node* twoHead=new node(10);

   node* tail_zero=zeroHead;
   node* tail_one=oneHead;
   node* tail_two=twoHead;

   node* temp=head;
   while(temp!=nullptr)
   {
    if(temp->data==0)
    {
     tail_zero->next=temp;
     tail_zero=temp;
    }
    else if(temp->data==1)
    {
     tail_one->next=temp;
     tail_one=temp;
    }
    else if(temp->data==2)
    {
     tail_two->next=temp;
     tail_two=temp;
    }
  
    temp=temp->next;
   }

    //remember Sajal! in this question you have to consider the edge cases  with caution...
    tail_zero->next=(oneHead->next!=nullptr)?oneHead->next:twoHead->next;
    tail_one->next=twoHead->next;
    tail_two->next=nullptr;
    

    head=zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    return head;
}


void tarversal(node *root)
{
    node *current=root;
    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }

}

int main()
{
    node *root=createSinglyLinkedList();
    node *newHead=sortedLinkedList(root);
    tarversal(newHead);
}
