#include<bits/stdc++.h>
using namespace std;

class minHeap {
    public:
    int *arr;
    int size;
    int capacity;

    minHeap(int cap) {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }

    int left(int i) {
        return 2*i+1;
    }

    int right(int i) {
        return 2*i+2;
    }

    int parentNode(int i) {
        return (i-1)/2;
    }

    void insertion(int x) {
        if(size == capacity) return;

        size++;
        arr[size-1] = x;

        for(int i = size-1; i != 0 && arr[parentNode(i)] > arr[i];) {
            swap(arr[parentNode(i)], arr[i]);
            i = parentNode(i);
        }
    }

    void heapify(int i) {
        int left_child_index = left(i);
        int right_child_index = right(i);
        int smallest = i;

        if(left_child_index < size && arr[left_child_index] < arr[smallest]) {
            smallest = left_child_index;
        }

        if(right_child_index < size && arr[right_child_index] < arr[smallest]) {
            smallest = right_child_index;
        }

        if(i != smallest) {
            swap(arr[smallest], arr[i]);
            heapify(smallest);
        }
    }

    int getminimum() {
        return arr[0];
    }

    int extractMin() {
        if(size == 0) return INT_MAX;
        if(size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapify(0);

        return root;
    }

    void decreaseKey(int i, int x) {
        if(i >= size) return;

        arr[i] = x;
        while(i != 0 && arr[parentNode(i)] > arr[i]) {
            swap(arr[i], arr[parentNode(i)]);
            i = parentNode(i);
        }

    }


    void deletion(int i)
    {
        if(i>=size)
        return;

        
        decreaseKey(i,INT_MIN);
        extractMin();
    }
};

int main() {
    minHeap h(11);
    h.insertion(10);
    h.insertion(40);
    h.insertion(20);
    h.insertion(80);
    h.insertion(100);
    h.insertion(70);

    cout << "\nThe minHeap before calling the decrease function:" << endl;
    for(int i = 0; i < h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << "\nThe minimum is " << h.getminimum() << endl;

    h.decreaseKey(3, 5); // Decrease the value at index 3 to 5

    cout << "\nThe minHeap after calling the decrease function:" << endl;
    for(int i = 0; i < h.size; i++) {
        cout << h.arr[i] << " ";
    }

     h.deletion(3);
      cout << "\nThe final minHeap is :" << endl;
    for(int i = 0; i < h.size; i++) {
        cout << h.arr[i] << " ";
    }
    return 0;
}
