#include<bits/stdc++.h>
using namespace std;
class minHeap
{
    public:
    int *arr;
    int size;
    int capacity;

    minHeap(int cap)
    {
        arr=new int[cap];//dynamically 10 size ka array bana liya...
        size=0;//abhi koio nhi aay hai..
        capacity=cap;
    }

    int left_child(int i)
    {
        return 2*i+1;
    }

    int right_child(int i)
    {
        return 2*i+2;
    }

    int parentNode(int i)
    {
        return (i-1)/2;
    }

    
    
 void insertion(int x)
    {
        if(size==capacity)
        {
         return;
        } 

        size++;
        arr[size-1]=x;
        //now we are implementing the min heap
       int i = size - 1;
        while (i != 0 && arr[i] < arr[parentNode(i)]) {
            swap(arr[i], arr[parentNode(i)]);
            i = parentNode(i);
        }
    }
};
int main() 
{ 
    minHeap h(11);
    h.insertion(3); 
    h.insertion(2);
    h.insertion(15);
    h.insertion(20);


    // Optional: Print heap array to verify
    for (int i = 0; i < h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    return 0;
} 