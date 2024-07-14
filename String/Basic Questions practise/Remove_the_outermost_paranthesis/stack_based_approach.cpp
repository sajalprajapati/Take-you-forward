#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) 
{
    string res="";
        stack<char> st;
        int i=0;
        while(i<s.size()){
            char ch = s[i];
            if(ch =='('){
                if(st.size()>0)
                res += ch;
                st.push(ch);
            }
            else{
                if(st.size()>1){
                    res +=')';
                }
                st.pop();
            }
          

            i++;
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