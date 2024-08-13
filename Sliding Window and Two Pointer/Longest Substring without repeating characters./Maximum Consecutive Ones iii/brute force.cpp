#include<bits/stdc++.h>
using namespace std;
int longestConsecutiveOnes(vector<int> &v,int k)
{
    int n=v.size();
    if(n==1 or n==0)
    return n;

    int maxLength=0;
    
    for(int i=0;i<n;i++)
    {
        int zeroesCount=0;
        for(int j=i;j<n;j++)
        {
          if(v[j]==0)
          zeroesCount++;
          else if(zeroesCount<=k)
          {
            int length=j-i+1;
            maxLength=max(maxLength,length);
          }
          else
          break;
        }
    }

    return maxLength;
}
int main()
{
    vector<int> v;
    int size;
    cout<<"\n enter the size of the vector"<<endl;
    cin>>size;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
     int element;
     cin>>element;
     v.push_back(element);
    }

     cout<<"\n the longest maximum consecutive ones is"<<longestConsecutiveOnes(v,2);
}