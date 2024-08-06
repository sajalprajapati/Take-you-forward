#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch)
{
    return ((ch>='A' and ch<='Z')or(ch>='a' and ch<='z')or(ch>=0 and ch<=9));
}
string postfixToInfix(string &s)
{
    int n=s.length();
    int i=n-1;
    stack<string> stk;
    while(i>=0)
    {
        if(isOperand(s[i]))
        {
            stk.push(string(1,s[i]));
        }

        else
        {
            string t1=stk.top(); stk.pop();
            string t2=stk.top(); stk.pop();
            string concat='('+t1+s[i]+t2+')';
            stk.push(concat);
        }
        i--;
    }

    return stk.top();
}
int main()
{
    string s;
    cout<<"\n enter your string ";
    cin>>s;
    cout<<"\n the infix is "<<postfixToInfix(s);
}