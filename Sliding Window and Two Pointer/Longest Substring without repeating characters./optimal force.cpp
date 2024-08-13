#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> hashmap(256,-1); //<-------------we have created an vector of length 256 in which at the starting there is no element present hence answer is -1;
        int l=0;
        int r=0;
        int maxLength=0;

        while(r<s.length())
        {
           //ya to element milega
           if(hashmap[s[r]]!=-1)
           {
            if(hashmap[s[r]]>=l)
            {
                l=hashmap[s[r]]+1;
            }
           }

           //ya toh element nhi milega..
           int length=(r-l)+1;
           maxLength=max(length,maxLength);
           hashmap[s[r]]=r;
           /*
           r=0;
           s[r]='a'
           hashmap[s[r]]=hashmap[a]=hashmap[97].
           */

          r++;
        }

        return maxLength;
    }
};
int main()
{
    Solution sol;
    string str;
    cout<<"\n enter the string";
    cin>>str;
    int number=sol.lengthOfLongestSubstring(str);
    cout<<"\n the length is "<<number; 
}