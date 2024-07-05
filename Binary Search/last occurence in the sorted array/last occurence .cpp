#include<bits/stdc++.h>
using namespace std;
int last_occurence(vector<int> &v,int target)

{
  int lower=0;
  int higher=(v.size())-1;
  int res=-1;

  while(lower<=higher)
  {
    int middle=lower+(higher-lower)/2;

    if(v[middle]==target)
    {
       lower=middle+1;
        res=middle;
    }

    else if(v[middle]>target)
    {
        higher=middle-1;
    }

    else if( v[middle]<target)
    {
        lower=middle+1;
    }
  }

  return res;
}

int main()
{
    vector<int> v;
    int size;
    cout<<"\n enter the size of the elements in the vector"<<endl;
    cin>>size;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

    int target;
    cout<<"\n enter the target value"<<endl;
    cin>>target;

    int result= last_occurence(v,target);
    if(result!=-1)
    {
        cout<<"\n the last occurence of the element is present at the index "<<result<<endl;
    }
    else
    {
        cout<<"\n their is no last occurence of the element"<<endl;
    }
}