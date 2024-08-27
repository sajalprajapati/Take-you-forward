 int helper(int i, int j, int m, int n, vector<vector<int>>& arr,vector<vector<int>> &dp)
    {
        // Base cases
        if (i >= m || j >= n || arr[i][j] == 1) 
            return 0;  // Out of bounds or obstacle

        if (i == m-1 && j == n-1)
            return 1;  // Reached the bottom-right corner

        if(dp[i][j]!=-1) return dp[i][j];
        // Recursive calls for right and bottom moves
        int right = helper(i, j + 1, m, n, arr,dp);
        int bottom = helper(i + 1, j, m, n, arr,dp);

        return dp[i][j]= right + bottom;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting or ending point is blocked, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(0, 0, m, n, obstacleGrid,dp);
    }