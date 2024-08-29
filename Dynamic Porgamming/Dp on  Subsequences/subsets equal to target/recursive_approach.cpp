#include<bits/stdc++.h>
using namespace std;
bool helper(int index,int target,vector<int> arr)
{
    if(target==0) return true;

    if(index==arr.size()) return (target==0);

    //not pick condition..that is in my mind..
    if(helper(index+1,target,arr)==true) return true;

    //pick condition
    if(target>=arr[index])
    {
        if(helper(index+1,target-arr[index],arr)==true) return true;
    }

    return false;
}

bool isSubsetSum(vector<int>arr, int sum)
{
  return helper(0,sum,arr);     
}

int main()
{
    int size;
    cout<<"\n enter the size of the vector"<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        arr.push_back(element);
    }

    int target;
    cout<<"\n enter the target value"<<endl;
    cin>>target;

    bool answer=isSubsetSum(arr,target);
    if(answer==true)
    cout<<"\n yes"<<endl;
    else
    cout<<"\n no"<<endl;
}