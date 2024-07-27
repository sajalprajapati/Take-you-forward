#include<bits/stdc++.h>
using namespace std;
void subsequencePrintingSumEqualTok(int index,vector<int> &answer,vector<int> &original,int equivalentSum,int Givensum,int &count)
{
  if(index==original.size())
  {   
    if(equivalentSum==Givensum)
  {
        count=count+1;
  }
    return ;
  }

   

  answer.push_back(original[index]);
  equivalentSum=equivalentSum+original[index];
  subsequencePrintingSumEqualTok(index+1,answer,original,equivalentSum,Givensum,count);

  answer.pop_back();
  equivalentSum=equivalentSum-original[index];
  subsequencePrintingSumEqualTok(index+1,answer,original,equivalentSum,Givensum,count);
   
}
int main()
{
    vector<int> original;
    int size;
    cout<<"\n enter the size of the vector";
    cin>>size;
    cout<<"\n enter the elements in the vector";
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        original.push_back(element);
    }

    int sum;
    cout<<"\n enter the sum value";
    cin>>sum;

    int count=0;
    vector<int> answer;
    subsequencePrintingSumEqualTok(0,answer,original,0,sum,count);
    cout<<"\n the count is "<<count;
}