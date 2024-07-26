#include<bits/stdc++.h>
using namespace std;
void reversing(int i,int arr[],int sizeOfArray)
{
   if(i>=(sizeOfArray/2))
   return;

   swap(arr[i],arr[sizeOfArray-i-1]);
   reversing(i+1,arr,sizeOfArray);
}
int main()
{
    int sizeOfArray;
    cout<<"\n enter the size of the arrar"<<endl;
    cin>>sizeOfArray;
    int arr[sizeOfArray];
    cout<<"\n enter the elements in the array";
    for(int i=0;i<sizeOfArray;i++)
    {
        cin>>arr[i];
    }

    reversing(0,arr,sizeOfArray);
    cout<<"\n the array after the reversal is"<<endl;
    for(int i=0;i<sizeOfArray;i++)
    {
        cout<<arr[i]<<" ";
    }
}