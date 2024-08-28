#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int helper(int i,int j,int m,int n,vector<vector<int>> &arr)
    {
      if(i==m-1 and j==n-1)
      {
        return arr[i][j];
      }

      if(i>=m or j>=n)
      {
        return INT_MAX;
      }

      int right=helper(i,j+1,m,n,arr);
      int bottom=helper(i+1,j,m,n,arr);

      return arr[i][j]+min(right,bottom);
    } 

    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();

        return helper(0,0,m,n,grid);
    }
};

int main()
{
    int m,n;
    cout<<"\n enter the value of m and n"<<endl;
    cin>>m>>n;

    vector<vector<int>> v(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }

    Solution sol;
    cout<<"\n the minimum value at the path is "<<sol.minPathSum(v);
}