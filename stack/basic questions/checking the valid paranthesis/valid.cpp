#include<bits/stdc++.h>
using namespace std;
bool validParanthesis(string &s)
{
    if(s.length()==0 or s.length()==1)
    return false;

    stack<char> stk;
    for(auto it:s)
    {
        
        if(it=='(' or it=='[' or it=='{')
        stk.push(it);
        else
        {
            char ch=stk.top();
            stk.pop();
            if((ch=='(' and it==')')or(ch=='[' and it==']')or(ch=='{' and it=='}')) continue;
            else return false;
        }
    }

    return stk.empty();
}
int main()
{
    string s;
    cout<<"\n enter the string value";
    cin>>s;
    bool answer=validParanthesis(s);
    if(answer==true)
    {
        cout<<"\n the string is valid ";
    }
    else
    {
        cout<<"\n the string is not valid";
    }
}