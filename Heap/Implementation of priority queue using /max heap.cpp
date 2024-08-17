#include<bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    public:
    vector<int> heap;

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

    void push(int data)
    {
        heap.push_back(data);

        for(int i=heap.size()-1; i!=0 and heap[parentNode(i)]<heap[i];)
        {
            swap(heap[parentNode(i)],heap[i]);
            i=parentNode(i);
        }
    }

    void maxHeapify(int i)
    {
        int left_child_index=leftchild(i);
        int right_child_index=rightchild(i);
        int largest=i;

        if(left_child_index<heap.size() and heap[left_child_index]>heap[largest])
        {
            largest=left_child_index;
        }

        if(right_child_index<heap.size() and heap[right_child_index]>heap[largest])
        {
            largest=right_child_index;
        }

        if(i!=largest)
        {
            swap(heap[largest],heap[i]);
            maxHeapify(largest);
        }
    }

    void pop() //<----this pop is extarct maximum which is present at the 0th index...
    {
        if(heap.size()==0)
        {
            cout<<"\n the priority queue is empty";
            return;
        }


        if(heap.size()==1)
        {
            int root=heap[0];
            heap.pop_back();
        }

        int root=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        
        maxHeapify(0);
    }

    int top()
    {
         if (heap.size() == 0)
        {
            cout << "\nThe priority queue is empty";
            return INT_MIN; // Returning INT_MAX if the queue is empty.
        }
        return heap[0];
    }

    bool empty() 
    { return heap.size() == 0; }

    // Function to get the size of the priority queue
    int size() 
    { return heap.size(); }
};


int main()
{
    PriorityQueue pq;

    pq.push(12);
    pq.push(13);
    pq.push(45);
    pq.push(67);
    pq.push(67);

  cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl;

    pq.pop();
    cout << "Top element after another pop: " << pq.top() << endl;

    cout << "Is the priority queue empty? " << (pq.empty() ? "Yes" : "No") << endl;

    return 0;
    
}

