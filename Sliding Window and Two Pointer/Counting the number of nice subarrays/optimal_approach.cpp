#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int counting_the_subarrays(vector<int> &nums,int k)
    {
        int n=nums.size();
        if(k<0) return 0;
        if(n==0 or n==1)
        return n;

        int left=0,right=0,count=0,sum=0;
        while(right<n)
        {
            sum=sum+(nums[right]%2);

            //if(sum>k)
            while(sum>k)
            {
                sum=sum-(nums[left]%2);
                left++;
            }

            //else if(sum<=k)
            if(sum<=k)
             count =count+(right-left+1);
             right++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int left=counting_the_subarrays(nums,k);
        k=k-1;
        int right=counting_the_subarrays(nums,k);
        return left-right;
    }
};
int main()
{
    int size;
    cout<<"\n enter the size of the vector"<<endl;
    cin>>size;
    vector<int> nums;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        nums.push_back(element);
    }

    int k;
    cout<<"\n enter the value of k";
    cin>>k;
    Solution sol;
    cout<<"\n the count is "<<sol.numberOfSubarrays(nums,k);
}