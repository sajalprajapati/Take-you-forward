#include<bits/stdc++.h>
using namespace std;
//only condiition is that it will take O(N^N) time and space = O(1).
class Solution {
public:
int largestRectangleArea(vector<int>& heights) 
{
  int res=0;

  for(int i=0;i<heights.size();i++)
  {
    int current=heights[i];

    for(int j=i-1;j>=0;j--)
    {
        if(heights[j]>=heights[i])
        {
            current=current+heights[i];
        }
        else
        {
            break;
        }
    }

    for(int j=i+1;j<heights.size();j++)
    {
        if(heights[j]>=heights[i])
        {
            current=current+heights[i];
        }
        else
        {
            break;
        }
    }

    res=max(res,current);
  }

  return res;        
}
};