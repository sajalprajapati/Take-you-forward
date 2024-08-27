#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int helper(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
          //writing the base case condition:
          if(i==m-1 and j==n-1)
          {
            return 1;
          }

          if(i>=m or j>= n)
          {
            return 0;
          }

          if(dp[i][j]!=-1) return dp[i][j];

          int right=helper(i,j+1,m,n,dp);
          int bottom=helper(i+1,j,m,n,dp);

          return dp[i][j]=right+bottom;
    }


    int uniquePaths(int m, int n) 
    {
          vector<vector<int>> dp(m,vector<int> (n,-1));
          return helper(0,0,m,n,dp);
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