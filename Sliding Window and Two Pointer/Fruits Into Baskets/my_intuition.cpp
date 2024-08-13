#include<bits/stdc++.h>
using namespace std;
int totalFruits(vector<int> &arr)
{
    int n=arr.size();
    if(n==0 or n==1)
    return n;

    int maxLength=0;
    for(int i=0;i<n;i++)
    {
        set<int> mali;
        for(int j=i;j<n;j++)
        {
          mali.insert(arr[j]);

          if(mali.size()>2)
          {
            break;
          }
         
         maxLength=max(maxLength,j-i+1);
         
        }
    }

    return maxLength;
}
int main()
{
   vector<int> arr;
   int size;
   cout<<"\n enter the size of the vector";
   cin>>size;
   cout<<"\n enter the elements in the vector"<<endl;
   for(int i=0;i<size;i++)
   {
    int element;
    cin>>element;
    arr.push_back(element);
   }
   
   cout<<"\n the length is "<<totalFruits(arr);
}