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
        arr=new int[cap];
        size=0;
        cap=capacity;
    }
 
    int left(int i)
    {
        return 2*i+1;
    }


    int right(int i)
    {
        return 2*i+2;
    }

    int parentNode(int i)
    {
        return (i-1)/2;
    }
    void insertion(int data)
    {
        if(size==capacity)
        {
            return;
        }

        size++;
        arr[size-1]=data;
        for(int i=size-1;i!=0 and arr[parentNode(i)]>arr[i];)
        {
            swap(arr[parentNode(i)],arr[i]);
            i=parentNode(i);
        }
      
    } 

    //minHeapify mtlb jo humrha minheap jo ki glt banhua hai..usko shi karna...
    void minHeapify(int i)
    {
        int left_child_index=left(i);
        int right_child_index=right(i);
        int smallest=i;

        if(left_child_index<size and arr[left_child_index]<arr[smallest])
        {
            smallest=left_child_index;
        }

        if(right_child_index<size and arr[right_child_index]<arr[smallest])
        {
            smallest=right_child_index;
        }

        if(smallest!=i)
        {
            swap(arr[smallest],arr[i]);
            minHeapify(smallest);
        }
    }

    int extractMinimum()
    {
        if(size==0)
        return INT_MAX;
        if(size==1)
        return arr[0];

       
        swap(arr[0],arr[size-1]);
         size--;
        minHeapify(0);

        return arr[size];
    }

    int getMinimum()
    {
        return arr[0];
    }
};


int main()
{
    minHeap h(11);
    h.insertion(10);
    h.insertion(23);
    h.insertion(1);
    h.insertion(2);
    h.insertion(100);

    int size=h.size;

    for(int i=0;i<size;i++)
    {
        cout<<h.arr[i]<<" ";
    }

    cout<<"\n before the minheapify function,the smallest value is "<<h.getMinimum();
    cout<<"\n the minimum element present is "<<h.extractMinimum();
}