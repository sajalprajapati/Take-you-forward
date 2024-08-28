class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&arr,vector<vector<int>> &dp)
    {
       int n=arr.size();
       if(j<0 or j>=n) return 1e9;

       if(i==n-1)
       return arr[n-1][j];

       if(dp[i][j]!=-1) return dp[i][j];
       int left_diagonal=arr[i][j]+helper(i+1,j-1,arr,dp);
       int bottom=arr[i][j]+helper(i+1,j,arr,dp);
       int right_diagonal=arr[i][j]+helper(i+1,j+1,arr,dp);

       return dp[i][j]=min(left_diagonal,min(bottom,right_diagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
      int n=matrix.size();
      vector<vector<int>> dp(n,vector<int>(n,-1));
      int minimum=INT_MAX;
      for(int j=0;j<n;j++)
      {
        minimum=min(minimum,helper(0,j,matrix,dp));
      }
      return minimum;    
    }
};