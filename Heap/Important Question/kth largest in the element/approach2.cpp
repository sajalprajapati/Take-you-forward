#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
      priority_queue<int,vector<int>,greater<int>> pq;

      for(auto it:nums)
      {
        pq.push(it);
        if(pq.size()>k)
        pq.pop();
      }

      return pq.top();
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