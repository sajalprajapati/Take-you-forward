#include<bits/stdc++.h>
using namespace std;
int maximumNestingDepth(string s)
{
    stack<int> st;
    int maximum=0;
    for(int i=0;i<s.size();i++)
    {
        int stack_size;
        if(s[i]=='(')
        {
          st.push(s[i]);
          stack_size=st.size();
          maximum=max(maximum,stack_size);
        }
        else if(s[i]==')')
        {
         st.pop();
        }
    }

    return maximum;
}
int main()
{
    string s;
    cout<<"\n enter your string "<<endl;
    cin>>s;

    int answer=maximumNestingDepth(s);
    cout<<"\n the maximum nesting paranthesis is "<<answer;
}