#include<bits/stdc++.h>
using namespace std;
int priority(char ch)
{
    if(ch=='^')
    return 3;

    if(ch=='*' or ch=='/')
    return 2;

    if(ch=='+' or ch=='-')
    return 1;

    else 
    return -1;
}
string InfixToPostFix(string &s)
{
    int n=s.length();
    int i=0;
    string expression="";
    stack<char> stk;

    while(i<n)
    {
        //applying for the condition of the pushing of the operand.
        if((s[i]>='A' and s[i]<='Z')or(s[i]>='a' and s[i]<='z')or(s[i]>=0 and s[i]<=9))
        {
            expression=expression+s[i];
        }

       else if(s[i]=='(') stk.push(s[i]);

       else if(s[i]==')')
       {
        while(!stk.empty()and stk.top()!='(')
        {
            expression=expression+stk.top();
            stk.pop();
        }
          stk.pop(); // Pop the '('
       }

       else 
       {
        // we will be playing choti jaat and badi jaat
        /*
        example : i is pointing to '-' _____________________stk.top()="^"
        */
        while(!stk.empty() and priority(s[i])<=priority(stk.top()))
        {
            expression=expression+stk.top();
            stk.pop();
        }

        stk.push(s[i]);
       }
       i++;
    }


    while(!stk.empty())
    {
        expression=expression+stk.top();
        stk.pop();
    }


    return expression;
}
int main()
{
    string s;
    cout<<"\n enter your string "<<endl;
    cin>>s;
    string answer=InfixToPostFix(s);;
    cout<<answer;
    
}#include<bits/stdc++.h>
using namespace std;
int priority(char ch)
{
    if(ch=='^')
    return 3;

    if(ch=='*' or ch=='/')
    return 2;

    if(ch=='+' or ch=='-')
    return 1;

    else 
    return -1;
}
string InfixToPostFix(string &s)
{
    int n=s.length();
    int i=0;
    string expression="";
    stack<char> stk;

    while(i<n)
    {
        //applying for the condition of the pushing of the operand.
        if((s[i]>='A' and s[i]<='Z')or(s[i]>='a' and s[i]<='z')or(s[i]>=0 and s[i]<=9))
        {
            expression=expression+s[i];
        }

       else if(s[i]=='(') stk.push(s[i]);

       else if(s[i]==')')
       {
        while(!stk.empty()and stk.top()!='(')
        {
            expression=expression+stk.top();
            stk.pop();
        }
          stk.pop(); // Pop the '('
       }

       else 
       {
        // we will be playing choti jaat and badi jaat
        /*
        example : i is pointing to '-' _____________________stk.top()="^"
        */
        while(!stk.empty() and priority(s[i])<=priority(stk.top()))
        {
            expression=expression+stk.top();
            stk.pop();
        }

        stk.push(s[i]);
       }
       i++;
    }


    while(!stk.empty())
    {
        expression=expression+stk.top();
        stk.pop();
    }


    return expression;
}
int main()
{
    string s;
    cout<<"\n enter your string "<<endl;
    cin>>s;
    string answer=InfixToPostFix(s);;
    cout<<answer;
    
}