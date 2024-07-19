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
        cout<<"\n enter the data for the  "<<i<<" th node";
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

int nthNodeFromtheEnd(node *head,int n)
{
  if(head==nullptr)
  return 0;

  int length=0;
  for(node* current=head;current!=nullptr;current=current->next)
  length++;

  if(length<n)
  return 0;

  node *current=head;
  for(int i=1;i<(length-n+1);i++)
  current=current->next;

  return current->data;
}

int main()
{
    node *root=createSinglyLinkedList();

    int n;
    cout<<"\n which node value you want to find out "<<endl;
    cin>>n;

    int answer=nthNodeFromtheEnd(root,n);
    if(answer==0)
    {
        cout<<"\n the length of the linked list is small "<<endl;
    }
    else
    cout<<"\n the number is "<<answer;
}