#include<bits/stdc++.h>
using namespace std;
vector<int> NearestSmallestNumber(vector<int> &v)
{
    if(v.size()==0 or v.size()==1)
    return {-1};

    int n=v.size();
    vector<int> answer(n,-1);
    stack<int> stk;

    for(int i=0;i<n;i++)
    {
        while(!stk.empty() and v[i]<=stk.top())
        stk.pop();

        if(!stk.empty())
        answer[i]=stk.top();

        stk.push(v[i]);
    }

    return answer;
}
int main()
{
    vector<int> v;
    int size;
    cout<<"\n enter the size of the vector";
    cin>>size;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }
    vector<int> answer=NearestSmallestNumber(v);
    for(auto &it:answer)
    {
        cout<<it<<" ";
    }
}