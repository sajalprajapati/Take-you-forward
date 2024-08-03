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
/*
   you can imagine like this :
   |-------| 
   |_______|<--------head is pointing over here.


   |-------|            |----------|  
   |_______|----------->|__________|
      ^
      |
      ^
      |
      <-----------head is now pointing here. 

      
       
*/
class MyStack
{
    public:
    node* head;
    int size;

    MyStack()
    {
        head=nullptr;
        size=0;
    }

    void push(int x)
    {
        //we would not get overflow condition in this pushing of the linked list .
        node* temp=new node(x);
        temp->next=head;
        head=temp;
        size++;  
    }

    int pop()
    {
        if(head==nullptr)
        {
            cout<<"\n the condition is underflow .Sorry! We can't delete anything ";
            return 0;
        }

        node* temp=head;
        head=head->next;
        delete(temp);
        size--;
    }


    int peek()
    {
        if(head==nullptr) 
        {
            cout<<"\n No element is present as stack is empty"<<endl;
            return 0;
        }

        return head->data;
    }

    bool isEmpty()
    {
        return (head==nullptr);
    }

    int sizeOfStack()
    {
        return size;
    }
};

int main()
{
    MyStack stk;
    cout<<"\n the stack has been created";
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout<<"\n the size of the stack is "<<stk.sizeOfStack();

    stk.pop();
    stk.pop();


}