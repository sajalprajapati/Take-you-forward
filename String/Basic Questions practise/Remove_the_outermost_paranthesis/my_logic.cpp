#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) 
{
    string res;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' && count==0)
                count++;
            else if(s[i]=='(' && count>=1){
                res+=s[i];
                count++;
            }   
            else if(s[i]==')' && count>1){
                res+=s[i];
                count--;
            }
            else if(s[i]==')' && count==1)
                count--;
        }
        return res; 
}

int main()
{
    string s;
    cout<<"\n enter your string "<<endl;
    cin>>s;
    string result=removeOuterParentheses(s);
    cout<<"\n the string after removing the outermost paranthesis is"<<result<<endl;
}