#include<bits/stdc++.h>
using namespace std;
int longestRepeatingCharacter(string &str,int k)
{
   int n=str.size();
   if(n==0 or n==1)
   return n;

   int maxlength=0;
   for(int i=0;i<n;i++)
   {
    vector<int> hashmap(26,0);
    int maximumFrequency=0;
    for(int j=i;j<n;j++)
    {
        hashmap[str[j]-'A']++;
        maximumFrequency=max(maximumFrequency,hashmap[str[j]]);
        int changes=((j-i+1))-maximumFrequency;
        if(changes<=k)
        maxlength=max(maxlength,changes);
        else
        break;
    }
   }

   return maxlength;
}

int main()
{
    string str;
    cout<<"\n enter the string"<<endl;
    cin>>str;
    int k;
    cout<<"\n enter the value of k";
    cin>>k;
    cout<<"\n the length of the string is "<<longestRepeatingCharacter(str,k);
}