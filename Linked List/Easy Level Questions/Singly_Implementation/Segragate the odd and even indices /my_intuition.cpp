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

node* oddEvenList(node* head)
{
    if(head==nullptr or head->next==nullptr)
    return head;

    node* oddHead=new node(10);
    node* evenHead=new node(10);
    node* tailOdd=oddHead;
    node* tailEven=evenHead;

    int count=1;;
    node* current=head;
    while(current!=nullptr)
    {
        if(count%2!=0)
        {
         tailOdd->next=current;
         tailOdd=current;
        }
        else
        {
         tailEven->next=current;
         tailEven=current;
        }

        count++; 
        current=current->next;
    }
 
   tailEven->next=nullptr;
   tailOdd->next=evenHead->next;
   head=oddHead->next;
   delete(oddHead);
   delete(evenHead);

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
    node *newHead=segragrateLinkedList(root);
    tarversal(newHead);
}
