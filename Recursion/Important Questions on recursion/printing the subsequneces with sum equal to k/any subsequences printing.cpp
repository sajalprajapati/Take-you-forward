#include<bits/stdc++.h>
using namespace std;
bool subsequencePrintingSumEqualTok(int index,vector<int> &answer,vector<int> &original,int equivalentSum,int Givensum)
{
  if(index==original.size())
  {
    if(equivalentSum==Givensum)
    {
        cout<<endl;
        cout<<"[";
        for(auto x:answer)
        cout<<x<<" ";
        cout<<"]";

        return true;
    }
    
    else  return false;
  }

  answer.push_back(original[index]);
  equivalentSum=equivalentSum+original[index];
  if(subsequencePrintingSumEqualTok(index+1,answer,original,equivalentSum,Givensum)==true)
  return true;;

  answer.pop_back();
  equivalentSum=equivalentSum-original[index];
  if(subsequencePrintingSumEqualTok(index+1,answer,original,equivalentSum,Givensum)==true)
  return true;

  return false;
   
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

    vector<int> answer;
    subsequencePrintingSumEqualTok(0,answer,original,0,sum);
}