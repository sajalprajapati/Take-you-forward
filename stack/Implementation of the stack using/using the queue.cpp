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

    bool isEmpty() {
        return (size == 0);
    }
};

class StackUsingSingleQueue {
    myQueue q;

public:
    void push(int x) {
        int s = q.sizeOfQueue();
        q.enqueue(x);

        // Rotate the queue to move the new element to the front
        for (int i = 0; i < s; i++) {
            int num = q.getFront();
            q.dequeue();
            q.enqueue(num);
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "\nStack is empty.";
            return;
        }
        q.dequeue();
    }

    int top() {
        if (q.isEmpty())
            return -1;
        return q.getFront();
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    StackUsingSingleQueue stack;
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
