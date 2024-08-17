#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int> &nums,int L,int R)
    {
        int pivot=nums[L];
        int i=L;
        int j=R;

        while(i<=j)
        {
            if(nums[i]<pivot and pivot<nums[j])
            {
             swap(nums[i],nums[j]);
             i++;
             j--;
            }

            else if(nums[i]>=pivot)
            {
                i++;
            }

            else if(nums[j]<=pivot)
            {
                j--;
            }
        }

        swap(nums[L],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
       int n=nums.size();
       int L=0;
       int R=n-1;
       int pivot_Index=0;

       while(true)
       {
        pivot_Index=partition(nums,L,R);

        if(pivot_Index==k-1)
        break;

        else if(pivot_Index>k-1)
        R=pivot_Index-1;

        else if(pivot_Index<k-1)
        L=pivot_Index+1;

       }


       return nums[pivot_Index];
    }
};
int main()
{
    Solution sol;
    int size;
    vector<int> v;
    cout<<"\n enter how many elements you want to push"<<endl;
    cin>>size;
    cout<<"\n enter the elements in the array"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }
    
    int k;
    cout<<"\n enter the value of k";
    cin>>k;
    cout<<"\n the value is "<<sol.findKthLargest(v,k);
}