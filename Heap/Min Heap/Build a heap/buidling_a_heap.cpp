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
        capacity=cap;
    }


    int leftchild(int i)
    {
        return 2*i+1;
    }

    int rightchild(int i)
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
        return ;

        size++;
        arr[size-1]=data;

        for(int i=size-1; i!=0 and arr[parentNode(i)]>arr[i];)
        {
            swap(arr[parentNode(i)],arr[i]);
            i=parentNode(i);
        }
    }
     
    void minHeapify(int i)
    {
        int left_child_index=leftchild(i);
        int right_child_index=rightchild(i);
        int smallest=i;

        if(left_child_index<size and arr[left_child_index]<arr[i])
        smallest=left_child_index;

        if(right_child_index<size and arr[right_child_index]<arr[i])
        smallest=right_child_index;

        if(i!=smallest)
        {
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    } 

    void buildHeap()
    {
        insertion(12);
        insertion(5346);
        insertion(45);
        insertion(451);
        insertion(787);
        insertion(123);
        int length=size-1;
        int parent=parentNode(length);
        for(int i=parent;i>=0;i--)
        {
            minHeapify(i);
        }
    }
};

int main()
{
   minHeap h(12);
   h.buildHeap();

   for(int i=0;i<h.size;i++)
   {
    cout<<h.arr[i]<<" ";
   }
   return 0;
}