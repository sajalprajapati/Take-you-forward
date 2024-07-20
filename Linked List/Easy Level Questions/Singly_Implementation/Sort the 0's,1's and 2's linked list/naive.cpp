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

   int count_zero=0;
   int count_one=0;
   int count_two=0;

  for(node* current=head;current!=nullptr;current=current->next)
  {
    if(current->data==0) count_zero++;
    else if(current->data==1) count_one++;
    else count_two++;
  }

  for(node* current=head;current!=nullptr;current=current->next)
  {
    if(count_zero) 
    {
        current->data=0;
        count_zero--;
    }
    else if(count_one) 
    {
        current->data=1;
        count_one--;
    }
    else 
    {
      current->data=2;
      count_two++;
    }
  }

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
