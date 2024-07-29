#include<bits/stdc++.h>
using namespace std;
bool isValid(string &str)
{
    stack<char> stk;
    for (char ch : str) {
        if (ch == '(') {
            stk.push(ch);
        } else if (ch == ')') {
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
void generatingParanthesis(string current,vector<string> &answer,int n)
{
    if(current.length()==2*n)
    {
        if(isValid(current))
        {
            answer.push_back(current);
        }
        return;
    }

    current.push_back('(');
    generatingParanthesis(current,answer,n);
    current.pop_back();


    current.push_back(')');
    generatingParanthesis(current,answer,n);
    current.pop_back();
}

vector<string> generateParenthesis(int n) 
{
  string current="";
  vector<string> answer;
  generatingParanthesis(current,answer,n);
  return answer;        
}
int main()
{
    int number;
    cout<<"\n  enter the numner of generating valid paranthesis"<<endl;
    cin>>number;
    vector<string> answer=generateParenthesis(number);
    for(const auto element: answer)
    {
        cout<<"[";
        cout<<element;
        cout<<"]";
    }
}