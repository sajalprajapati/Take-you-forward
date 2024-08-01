#include<bits/stdc++.h>
using namespace std;
class Solution 
{
 public:
 void CombinationsLogic(int idx,string &digits,string &temp,vector<string> &answer,unordered_map<char,string> &mp)
 {
    if(idx==digits.length())
    {
        answer.push_back(temp);
        return;
    }

    char ch=digits[idx];
    string str=mp[ch];

    for(int i=0;i<str.length();i++)
    {
        temp.push_back(str[i]);
        CombinationsLogic(idx+1,digits,temp,answer,mp);
        temp.pop_back();
    }
 }
 vector<string> letterCombinations(string digits) 
 {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";


        vector<string> answer;
        string temp="";
        CombinationsLogic(0,digits,temp,answer,mp);
        return answer;
 }
};

int main()
{
    Solution sol;
    string digits;
    cout<<"\n enter your string"<<endl;
    cin>>digits;
    vector<string> str=sol.letterCombinations(digits);
    for(auto &str1:str)
    {
        cout<<"["<<str1<<"]";
        cout<<endl;
    }
}