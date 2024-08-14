#include<bits/stdc++.h>
using namespace std;
/*
We are applying the formula:
length-maximumFrequency<=k
*/
int longestRepeatingCharacter(string &str,int k)
{
    int n=str.size();
    if(n==0 or n==1)
    return n;

    int left=0,right=0,maxLength=0,maxfrequency=0;
    vector<int> hashmap(26,0);

    while(right<n)
    {
        hashmap[str[right]-'A']++;
        maxfrequency=max(maxfrequency,hashmap[str[right]-'A']);

        while(((right-left+1)-maxfrequency)>k)
        {
            hashmap[str[left]-'A']--;
            maxfrequency=0;

            for(int i=0;i<25;i++)
            maxfrequency=max(maxfrequency,hashmap[i]);


            left++;
        }

        if(((right-left+1)-maxfrequency)<=k)
        maxLength=max(maxLength,right-left+1);

        right++; 
    }

    return maxLength;

}
int main()
{
    string str;
    cout<<"\n enter the string ";
    cin>>str;
    int k;
    cout<<"\n enter the value of k";
    cin>>k;
    cout<<"\n the length of the longest substring is "<<longestRepeatingCharacter(str,k);
}