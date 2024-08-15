#include<bits/stdc++.h>
using namespace std;

int longestSubstring(vector<string> &arr, int k)
{
   int n = arr.size();
   if (n == 0 || n == 1)
       return n;

   int left = 0, right = 0, maxlength = 0;
   unordered_map<string, int> mp;

   while (right < n)
   {
       mp[arr[right]]++;

       if (mp.size() <= k)
       {
           maxlength = max(maxlength, right - left + 1);
       }
       else if (mp.size() > k)
       {
           mp[arr[left]]--;
           if (mp[arr[left]] == 0)
               mp.erase(arr[left]);

           left++;
       }

       right++;
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
