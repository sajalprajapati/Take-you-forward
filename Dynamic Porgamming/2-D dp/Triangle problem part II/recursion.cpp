class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&arr)
    {
       int n=arr.size();
       if(j<0 or j>=n) return 1e9;

       if(i==n-1)
       return arr[n-1][j];

       int left_diagonal=arr[i][j]+helper(i+1,j-1,arr);
       int bottom=arr[i][j]+helper(i+1,j,arr);
       int right_diagonal=arr[i][j]+helper(i+1,j+1,arr);

       return min(left_diagonal,min(bottom,right_diagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
      int n=matrix.size();
      int minimum=INT_MAX;
      for(int j=0;j<n;j++)
      {
        minimum=min(minimum,helper(0,j,matrix));
      }
      return minimum;    
    }
};