#include<bits/stdc++.h>
using namespace std;

int longestSubstring(vector<string> &arr, int k)
{
   int n = arr.size();
   if (n == 0 || n == 1)
       return n;
 
  int maxlength=0;
  unordered_map<string,int> mp;

  for(int i=0;i<n;i++)
  {
    mp.clear();
    for(int j=i;j<n;j++)
    {
        mp[arr[j]]++;

        if(mp.size()<=2)
        maxlength=max(maxlength,j-i+1);
        else
        break;
    }
  }
   return maxlength;
}

int main()
{
    vector<string> v;
    int size;
    cout << "\nEnter the size of the vector: ";
    cin >> size;
    cout << "\nEnter the elements in the vector: ";
    for (int i = 0; i < size; i++)
    {
        string element;
        cin >> element;
        v.push_back(element);
    }

    int k;
    cout << "\nEnter the value of k: ";
    cin >> k;
    cout << "\nThe longest substring is " << longestSubstring(v, k) << endl;
}
