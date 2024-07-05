#include<bits/stdc++.h>
using namespace std;
 int findMin(vector<int>& nums) 
{
      int lower=0;
      int higher=(nums.size())-1;
      int minimum=INT_MAX;
      while(lower<=higher)
      {
        int middle=lower+(higher-lower)/2;
       
        //checking which part is sorted to apply 
        //binary search.
        //for left sorted...
        if(nums[lower]<=nums[middle])
        {
          minimum=min(minimum,nums[lower]);
          lower=middle+1;
        }
        else if(nums[middle]<nums[higher])
        {
          minimum=min(minimum,nums[middle]);
          higher=middle-1;
        }
      }

     return minimum;   
}

int main()
{
    vector<int> v;
    int size;
    cout<<"\n enter the size of the element in the array"<<endl;
    cin>>size;
    cout<<"\n enter the element in the array"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

    int minimum=findMin(v);
    cout<<"\n the minimum element in the rotated sorted array is "<<minimum;

}