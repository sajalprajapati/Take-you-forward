#include<bits/stdc++.h>
using namespace std;
class minHeap
{
    public:
    int []arr;
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
};