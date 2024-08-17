#include<bits/stdc++.h>
using namespace std;

class maxHeap
{
    public:
    int *arr;
    int size;
    int capacity;

    maxHeap(int cap)
    {
        arr = new int[cap];
        size = 0;
        capacity = cap; // Correcting this line to set capacity properly
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int parentNode(int i)
    {
        return (i - 1) / 2;
    }

    void insertion(int data)
    {
        if (size == capacity)
        {
            return;
        }

        size++;
        arr[size - 1] = data;
        for (int i = size - 1; i != 0 && arr[parentNode(i)] < arr[i];)
        {
            swap(arr[parentNode(i)], arr[i]);
            i = parentNode(i);
        }
    } 

    // maxHeapify to correct the heap structure
    void maxHeapify(int i)
    {
        int left_child_index = left(i);
        int right_child_index = right(i);
        int largest = i;

        if (left_child_index < size && arr[left_child_index] > arr[largest])
        {
            largest = left_child_index;
        }

        if (right_child_index < size && arr[right_child_index] > arr[largest])
        {
            largest = right_child_index;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            maxHeapify(largest);
        }
    }

    int extractMaximum()
    {
        if (size == 0)
            return INT_MIN;
        if (size == 1)
            return arr[0];

        swap(arr[0], arr[size - 1]);
        size--;
        maxHeapify(0);

        return arr[size];
    }

    int getMaximum()
    {
        return arr[0];
    }
};

int main()
{
    maxHeap h(11);
    h.insertion(10);
    h.insertion(23);
    h.insertion(1);
    h.insertion(2);
    h.insertion(100);

    int size = h.size;

    for (int i = 0; i < size; i++)
    {
        cout << h.arr[i] << " ";
    }

    cout << "\nBefore the maxHeapify function, the largest value is " << h.getMaximum();
    cout << "\nThe maximum element present is " << h.extractMaximum();
}
