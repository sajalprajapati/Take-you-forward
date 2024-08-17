#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
       priority_queue<int> pq(nums.begin(),nums.end());
       int ans=0;

       while(k--)
       {
        ans=pq.top();
        pq.pop();
       }    

       return ans;
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