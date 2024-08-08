#include<bits/stdc++.h>
using namespace std;
vector<int> previousSmallerElementIndices(vector<int> &heights,int n)
{
  vector<int> answer(n);
  stack<int> stk;
  
  for(int i=0;i<n;i++)
  {
    if(stk.empty())
    {
        answer[i]=-1;
    }
    else
    {
        while(!stk.empty() and heights[i]<=heights[stk.top()])
        {
            stk.pop();
        }

        if(stk.empty())
        {
            answer[i]=-1;
        }
        else
        {
            answer[i]=stk.top();
        }
    }

    stk.push(i);
  }

  return answer;
}


vector<int> nextSmallerElementIndices(vector<int> &heights,int n)
{
   vector<int> answer(n);
  stack<int> stk;
  
  for(int i=n-1;i>=0;i--)
  {
    if(stk.empty())
    {
        answer[i]=n;
    }
    else
    {
        while(!stk.empty() and heights[i]<=heights[stk.top()])
        {
            stk.pop();
        }

        if(stk.empty())
        {
            answer[i]=n;
        }
        else
        {
            answer[i]=stk.top();
        }
    }

    stk.push(i);
  }

  return answer;
}
class Solution 
{
 public:
 int largestRectangleArea(vector<int>& heights) 
 {
    int res=0;
    int n=heights.size();
    vector<int> previousSmallerElement=previousSmallerElementIndices(heights,n);
    vector<int> nextSmallerElement=nextSmallerElementIndices(heights,n);

    for(int i=0;i<n;i++)
    {
        int totalNo_Of_bars=(nextSmallerElement[i]-previousSmallerElement[i])-1;
        int totalarea_Of_a_bar=heights[i]*totalNo_Of_bars;
        res=max(res,totalarea_Of_a_bar); 
    }

    return res;
 }
   

};