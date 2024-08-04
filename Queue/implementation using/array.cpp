#include <bits/stdc++.h>
using namespace std;

class myQueue {
public:
    int capacity;
    int size;
    int *arr;

    // Constructor to initialize the queue with a given capacity
    myQueue(int x) {
        capacity = x;
        size = 0;
        arr = new int[capacity];
    }

    // Check if the queue is full
    bool isFull() {
        return (size == capacity);
    }

    // Enqueue an element into the queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << x << endl;
            return;
        }
        arr[size] = x;
        size++;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // Dequeue an element from the queue
    int pop() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return -1;
        }
        int frontElement = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return frontElement;
    }

    // Get the front element of the queue
    int getFront() {
        if (isEmpty())
            return -1;
        else
            return arr[0];
    }

    // Get the rear element of the queue
    int getRear() {
        if (isEmpty())
            return -1;
        else
            return arr[size - 1];
    }
};

int main() {
    myQueue q(5); // Create a queue of capacity 5
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl; // Should print 10
    cout << "Rear element: " << q.getRear() << endl;   // Should print 30

    cout << "Dequeued element: " << q.pop() << endl; // Should print 10
    cout << "Front element after dequeue: " << q.getFront() << endl; // Should print 20

    return 0;
}
