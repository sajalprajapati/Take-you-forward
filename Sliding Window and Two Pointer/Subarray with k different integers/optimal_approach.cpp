#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helperFunction(vector<int>& arr, int k)
    {
        int n=arr.size();
        if(n==0 or n==1)
        return n;

        int left=0,right=0,count=0;
        unordered_map<int,int> mp;
        while(right<n)
        {
            mp[arr[right]]++;

            while(mp.size()>k)
            {
                mp[arr[left]]--;
                if(mp[arr[left]]==0) mp.erase(arr[left]);
                left=left+1;
            }

            if(mp.size()<=k)
            {
                 count=count+(right-left+1);
            }
           
            right++;
        }
        
        return count;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) 
    {
       int count1=helperFunction(arr,k);
       int count2=helperFunction(arr,k-1);
       return count1-count2;   
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    int size;
    cout << "\nEnter the size of the vector: ";
    cin >> size;
    cout << "\nEnter the elements in the vector: ";
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    int k;
    cout << "\nEnter the value of k: ";
    cin >> k;
    cout << "\nThe longest substring is " << sol.subarraysWithKDistinct(v, k) << endl;
}
