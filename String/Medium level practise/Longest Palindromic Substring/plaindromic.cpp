#include<bits/stdc++.h>
using namespace std;
bool isPalindromic(string s,int i,int j)
{
  if(i>=j)
  return true;

  if(s[i]==s[j])
  return isPalindromic(s,i+1,j-1);

  return false;
}

string longestPalindromicSubstring(string s)
{
    int n=s.size();
    int maxLength=0;
    int startPointing=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(isPalindromic(s,i,j)==true)
            {
                if(j-i+1>maxLength)
                {
                    maxLength=j-i+1;
                    startPointing=i;
                }
            }
        }
    }

    return s.substr(startPointing,maxLength);
}
int main()
{
    string s;
    cout<<"\n enter your string "<<endl;
    cin>>s;
    string str=longestPalindromicSubstring(s);
    cout<<"\n the longest palindromic substring is "<<str;
}