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

    void dequeue() {
        if (size == 0) {
            cout << "\nNo deletion can be performed as no element has been inserted yet.";
            return;
        }
        node* del = front;
        front = front->next;
        delete del;
        size--;
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

class StackUsingQueues {
    myQueue Q1, Q2;

public:
    void push(int x) {
        Q2.enqueue(x);
        while (!Q1.isEmpty()) {
            int number = Q1.getFront();
            Q2.enqueue(number);
            Q1.dequeue();
        }

        swap(Q1, Q2);
    }

    void pop() {
        if (Q1.isEmpty()) {
            cout << "\nStack is empty.";
            return;
        }
        Q1.dequeue();
    }

    int top() {
        if (Q1.isEmpty())
            return -1;
        return Q1.getFront();
    }

    bool isEmpty() {
        return Q1.isEmpty();
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "Top element is: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop is: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after another pop is: " << stack.top() << endl;

    return 0;
}
