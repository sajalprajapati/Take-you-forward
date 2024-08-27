#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int helper(int i,int j,int m,int n)
    {
          //writing the base case condition:
          if(i==m-1 and j==n-1)
          {
            return 1;
          }

          if(i>m or j>n)
          {
            return 0;
          }

          int right=helper(i,j+1,m,n);
          int bottom=helper(i+1,j,m,n);

          return right+bottom;
    }


    int uniquePaths(int m, int n) 
    {
          return helper(0,0,m,n);
    }
};


int main()
{
    int n,m;
    cout<<"\n enter the value of m,n"<<endl;
    cin>>m>>n;
    Solution sol;
    cout<<"\n the total number of unique paths is "<<sol.uniquePaths(m,n);
}