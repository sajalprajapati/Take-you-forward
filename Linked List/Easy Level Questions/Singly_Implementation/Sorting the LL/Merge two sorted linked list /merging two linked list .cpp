#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node * next;

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
        cout<<"\n enter the data for the node "<<i<<" ";
        cin>>data;

        node *newnode=new node(data);

        

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


void taversal(node *head)
{
    node *current=head;
    while(current!=nullptr)
    {
        cout<<current->data<<" -> ";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}


node* mergeSortedLinkedList(node* list1, node* list2)
{
   if(list1==nullptr)
   {
    return list1;
   }
   else if(list2==nullptr)
   {
    return list2;
   }

   node* dummyNode=new node(-1);
   node* tail=dummyNode;
   while(list1!=nullptr and list2!=nullptr)
   {
      if(list1->data < list2->data)
      {
        tail->next=list1;
        tail=list1;
        list1=list1->next; 
      }

      else if(list2->data <list1->data)
      {
        tail->next=list2;
        tail=list2;
        list2=list2->next;
      }
   }


   if(list2!=nullptr)
   {
    tail->next=list2;
    tail=list2;
   }
   else
   {
    tail->next=list1;
    tail=list1;
   }

   return dummyNode->next;
}


int main()
{
    node *root1=createSinglyLinkedList();
    node *root2=createSinglyLinkedList();
    node *root3= mergeSortedLinkedList(root1,root2);
    cout<<"\n the merging of the two sorted linked list look like this "<<endl;
    taversal(root3);

}