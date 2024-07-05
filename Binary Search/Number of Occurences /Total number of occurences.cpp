#include<bits/stdc++.h>
using namespace std;
int first(vector<int> &v,int target)
{
    //to find the first occurences , we are immplementing the lower bound.


    int lower=0;
    int higher=(v.size())-1;
    int res=-1;
    while(lower<=higher)
    {
        int middle=lower+(higher-lower)/2;

        if(v[middle]>=target)
        {
            //since lower bound means finding the smallest index where the 
            //value at that is to be greatest to the target value or 
            //value at that index is to be equal to the target value.
            res=middle;
            higher=middle-1;
        }

        else
        {
            lower=middle+1;
        }
    }
    return res;
}

int last(vector<int> &v,int target)
{
    //now in order  to find the last occurences ,which satisfy our conditon that 
    /*
    Floor:

     Use when you need the largest value that doesn't exceed the target.
    */

   int lower=0;
   int higher=(v.size())-1;
   int res=-1;

   while(lower<=higher)
   {
    int middle=lower+(higher-lower)/2;

    if(v[middle]<=target)
    {
        res=middle;
        lower=middle+1;
    }
    else if(v[middle]>target)
    {
        higher=middle-1;
    }
   }

   return res;

}
int main()
{
    vector<int> v;
    int size;
    cout<<"\nenter the size of the elements in the vector"<<endl;
    cin>>size;
    cout<<"\n enter the elements in the vector "<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

    int target;
    cout<<"\nenter the value of target"<<endl;
    cin>>target;

    int first_occurences =first(v,target);
    int last_occurences=last(v,target);
    
    int total_occurences;
   
     if(first_occurences==-1)
     {
        cout<<"\n the total number of occurences is "<<0<<endl;
     }
     else
     {
        total_occurences=(last_occurences-first_occurences)+1;
      cout<<"\n the number of occurences is "<<total_occurences<<endl;
     }
    
}