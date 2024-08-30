//in this question we havee to count the total number of subset in which the sum of all the elements is equal to given target.
#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int helper(int index,int givenSum,int arr[])
{
    // if(givenSum==0) return 1;

    if(index==0)
    {
       if(arr[0]==0 and sum==0) return 2; 
       if(sum==0) return 1;
       if(sum==arr[0]) return 1;
       return 0;
    }

    int right=helper(index-1,givenSum,arr);
    int left=0;
    if(givenSum>=arr[index])
    {
        left=helper(index-1,givenSum-arr[index],arr);
    }

    return left+right;
}


int perfectSum(int arr[], int n, int sum)
{
    return helper(n-1,sum,arr)%MOD;
}

int main()
{
    int size;
    cout<<"\n enter the size of the element in the vector"<<endl;
    cin>>size;
    int arr[size];
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
      cin>>arr[i];
    }


    int targetSum;
    cout<<"\n enter the value of target sum"<<endl;
    cin>>targetSum;

    cout<<"\n the totalnumber of subset are "<<perfectSum(arr,size,targetSum);
}