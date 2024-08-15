#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) 
    {
      int n=arr.size();
      if(n==0 or n==1)
      return n;

      int count=0;
      unordered_map<int,int> mp;

      for(int i=0;i<n;i++)
      {
        mp.clear();
        for(int j=i;j<n;j++)
        {
            mp[arr[j]]++;

            if(mp.size()==k)
            count++;

            else if(mp.size()>k)
            break;
        }
      }

      return count;   
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
