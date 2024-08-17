#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    int *arr;      // Pointer to the heap array
    int size;      // Current number of elements in the heap
    int capacity;  // Maximum capacity of the heap

    // Constructor to initialize the heap with a given capacity
    MaxHeap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    // Function to return the index of the left child of a node at index i
    int left(int i) { return 2 * i + 1; }

    // Function to return the index of the right child of a node at index i
    int right(int i) { return 2 * i + 2; }

    // Function to return the index of the parent of a node at index i
    int parent(int i) { return (i - 1) / 2; }

    // Function to insert a new key into the max heap
    void insert(int key)
    {
        if (size == capacity)
        {
            cout << "Heap overflow" << endl;
            return;
        }

        // Insert the new key at the end
        size++;
        int i = size - 1;
        arr[i] = key;

        // Fix the max heap property if it is violated
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Function to remove the maximum element (root) from the max heap
    int extractMaximum()
    {
        if (size <= 0)
            return INT_MIN;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        // Store the maximum value and remove it from the heap
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        maxHeapify(0);

        return root;
    }

    // Function to decrease the value of a key at index i to a new value
    void decreaseKey(int i, int new_val)
    {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Function to delete a key at index i
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MAX);  // Increase the value to maximum
        extractMaximum();         // Remove the maximum element
    }

    // Function to get the maximum element (root) from the max heap
    int getMaximum() { return arr[0]; }

    // Function to heapify a subtree with root at given index i
    void maxHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    // Function to build a max-heap from an arbitrary array
    void buildHeap()
    {
        // Start from the last non-leaf node and heapify each node
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            maxHeapify(i);
        }
    }
};

int main()
{
    MaxHeap h(11);
    h.arr[0] = 3;
    h.arr[1] = 5;
    h.arr[2] = 9;
    h.arr[3] = 6;
    h.arr[4] = 8;
    h.arr[5] = 20;
    h.arr[6] = 10;
    h.arr[7] = 12;
    h.arr[8] = 18;
    h.size = 9;

    cout << "Array before building max-heap: ";
    for (int i = 0; i < h.size; i++)
        cout << h.arr[i] << " ";
    cout << endl;

    h.buildHeap();

    cout << "Array after building max-heap: ";
    for (int i = 0; i < h.size; i++)
        cout << h.arr[i] << " ";
    cout << endl;

    return 0;
}
