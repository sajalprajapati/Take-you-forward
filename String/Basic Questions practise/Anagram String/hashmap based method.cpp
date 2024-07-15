#include<bits/stdc++.h>
using namespace std;
bool validAnagram(const string &s,const string &goal)
{
    unordered_map<char,int> cnt1;
    unordered_map<char,int> cnt2;

    for(auto ch:s) cnt1[ch]++;
    for(auto ch:goal) cnt2[ch]++;

    return (cnt1==cnt2);
}
int main()
{
    string str1;
    string str2;
    cout<<"\n enter the string 1";
    cin>>str1;
    cin.ignore();
    cout<<"\nenter the string 2";
    cin>>str2;
    cin.ignore();

    int size1=str1.length();
    int size2=str2.length();

    if(size1<size2 or size2>size1)
    {
        cout<<"\n no possible for the anagram"<<endl;
    }
    else
    {
        bool answer=validAnagram(str1,str2);
        if(answer==true)
        {
            cout<<"\nthe strings are anagram"<<endl;
        }
        else
        {
            cout<<"\nthestrings are not anagram"<<endl;
        }
    }
}