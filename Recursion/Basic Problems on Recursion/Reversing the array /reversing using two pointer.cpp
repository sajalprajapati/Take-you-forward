#include<bits/stdc++.h>
using namespace std;
void reversing(int low,int arr[],int high)
{
   if(low>=high)
   return;

   swap(arr[low],arr[high]);
   reversing(low+1,arr,high-1);
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

    reversing(0,arr,sizeOfArray-1);
    cout<<"\n the array after the reversal is"<<endl;
    for(int i=0;i<sizeOfArray;i++)
    {
        cout<<arr[i]<<" ";
    }
}