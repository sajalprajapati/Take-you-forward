#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) 
{
    //since the array is strictly increasing ,thereby applying the binary search...
    int lower=0;
    int higher=arr.size()-1;

    while(lower<=higher)
    {
        int middle=lower+(higher-lower)/2;

        int kitne_number_missing_hai=arr[middle]-(middle+1);

        if(kitne_number_missing_hai<k)
        {
            lower=middle+1;
        }
        else
        {
            higher=middle-1;
        }
    }

    return lower+k;        
}
int main()
{
    int size;
    cout<<"\n enter the size of the positive numbers "<<endl;
    cin>>size;

    vector<int> v;
    cout<<"\n enter the positive numbers in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

    int kth;
    cout<<"\n which number-th missing number do you need"<<endl;
    cin>>kth;

    int result=findKthPositive(v,kth);
    cout<<kth<<" missing number is "<<result<<endl;
}