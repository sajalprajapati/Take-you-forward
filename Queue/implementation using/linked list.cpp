#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class myQueue {
public:
    node* front;
    node* rear;
    int size;

    myQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void enqueue(int x) {
        node* temp = new node(x);
        if (front == nullptr) {
            front = temp;
            rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "\nNo deletion can be performed as no element has been inserted yet.";
            return -1; // Return a value to indicate an error
        }
        node* del = front;
        int delData = del->data;
        front = front->next;
        delete del;
        size--;
        return delData;
    }

    int sizeOfQueue() {
        return size;
    }

    int getFront() {
        if (front == nullptr)
            return -1; // Return a value to indicate the queue is empty

        return front->data;
    }

    int getRear() {
        if (rear == nullptr) {
            return -1; // Return a value to indicate the queue is empty
        }

        return rear->data;
    }

    bool isEmpty() {
        return (size == 0);
    }
};

int main() {
    myQueue my; // Instantiate the queue without parentheses
    my.enqueue(5);
    my.enqueue(7);
    
    // Testing the functions
    cout << "Front element: " << my.getFront() << endl;
    cout << "Rear element: " << my.getRear() << endl;
    cout << "Size of queue: " << my.sizeOfQueue() << endl;
    
    cout << "Dequeued element: " << my.dequeue() << endl;
    cout << "Front element after dequeue: " << my.getFront() << endl;
    cout << "Size of queue after dequeue: " << my.sizeOfQueue() << endl;
    
    return 0;
}
