#include<bits/stdc++.h>
using namespace std;
int upper_bound(vector<int> &v,int target)
{
  int lower=0;
  int higher=(v.size())-1;

  while(lower<=higher)
  {
    int middle=lower+(higher-lower)/2;

    if(v[middle]>target)
    {
        higher=middle-1;
    }
    else if(v[middle]<=target) 
    {
        lower=middle+1;
    }
  }
  return lower;
}

int main()
{
    vector<int> v;
    int size;
    cout<<"\n enter the size of the element for your vector"<<endl;
    cin>>size;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }
    
    int target;
    cout<<"\n enter the value of target"<<endl;
    cin>>target;

    cout<<"the element is found at the index "<<upper_bound(v,target)<<endl;;
    
   
}
