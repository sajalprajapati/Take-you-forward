#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n==0 or n==1)
        return n;
        int count =0;

        for(int i=0;i<n;i++)
        {
            int k_copy=k;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2!=0)
                {
                    k_copy--;
                }
                if(k_copy==0)
                count++;
            }
        }

        return count;
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