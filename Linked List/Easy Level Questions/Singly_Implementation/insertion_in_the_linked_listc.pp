// #include<bits/stdc++.h>
// using namespace std;
// class node
// {
//     public:
//     int data;
//     node *next;

//     node(int data)
//     {
//         this->data=data;
//         this->next=nullptr;
//     }
// };

// node* CreateSinglyLinkedList()
// {
//     int number_of_nodes;
//     cout<<"\n enter the number of nodes"<<endl;
//     cin>>number_of_nodes;

//     node *head=nullptr;
//     node *tail=nullptr;
//     for(int i=0;i<number_of_nodes;i++)
//     {
//         int data;
//         cout<<"\n what value you want to insert in the node"<<endl;
//         cin>>data;

//         node *newnode=new node(data);

//         if(head==nullptr)
//         {
//             head=newnode;
//             tail=newnode;
//         }
//         else
//         {
//           tail->next=newnode;
//           tail=newnode;
//         }
//     }

//     return head;
// }


// node* insertion(node *head,int position)
// {
//     if(head==nullptr)
//     return head;

//     int data;
//     cout<<"\n enter the data you want to insert in the node that you want to insert "<<endl;
//     cin>>data;

//     node *newnode=new node(data);

//     if(position==1 and head->next==nullptr)
//     {
//         head->next=newnode;
//         return head;
//     }
//     else if(position==1 and head->next!=nullptr)
//     {
//         newnode->next=head->next;
//         head->next=newnode;

//         return head;
//     }


//    node *current=head;
//    int i=1;
//    while(i<position)
//    {
//     current=current->next;
//    }

//    newnode->next=current->next;
//    current->next=newnode;

//    return head;
// }

// void traversingSinglyList(node *head)
// {
//     node* current=head;

//     while(current!=nullptr)
//     {
//         cout<<current->data<<" ";
//         current=current->next;
//     }

//     if(head==nullptr)
//     {
//         cout<<"NULL"<<endl;
//     }
// }


// int main()
// {
//     node *root=CreateSinglyLinkedList();

//     int position;
//     cout<<"\n enter the position at which you want to insert the data"<<endl;
//     ;
//     cin>>position;

//    cout<<"\n the linked list before the insertion is "<<endl;
//    traversingSinglyList(root);


//    cout<<"\n the linked list after the insertion is"<<endl;
//    node *new_root=insertion(root,position);
//    traversingSinglyList(new_root);

    
// }


#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

node* CreateSinglyLinkedList() {
    int number_of_nodes;
    cout << "Enter the number of nodes: ";
    cin >> number_of_nodes;

    node *head = nullptr;
    node *tail = nullptr;

    for(int i = 0; i < number_of_nodes; i++) {
        int data;
        cout << "Enter the value you want to insert in the node: ";
        cin >> data;

        node *newnode = new node(data);

        if(head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    return head;
}

node* insertion(node *head, int position) {
    int data;
    cout << "Enter the data you want to insert: ";
    cin >> data;

    node *newnode = new node(data);

    if(position == 1) {
        newnode->next = head;
        return newnode;
    }

    node *current = head;
    for(int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if(current == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newnode;
        return head;
    }

    newnode->next = current->next;
    current->next = newnode;

    return head;
}

void traversingSinglyList(node *head) {
    node* current = head;

    while(current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int main() {
    node *root = CreateSinglyLinkedList();

    cout << "The linked list before the insertion is: " << endl;
    traversingSinglyList(root);

    int position;
    cout << "Enter the position at which you want to insert the data: ";
    cin >> position;

    node *new_root = insertion(root, position);

    cout << "The linked list after the insertion is: " << endl;
    traversingSinglyList(new_root);

    return 0;
}
