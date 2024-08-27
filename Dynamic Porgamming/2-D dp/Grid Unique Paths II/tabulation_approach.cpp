class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the starting or ending point is blocked, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        // Initialize the dp grid with 0s, using long long to prevent overflow
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Starting from the bottom-right corner
        dp[m-1][n-1] = 1;

        // Fill the dp grid from the bottom-right to the top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // No path through an obstacle
                } else {
                    if (i < m - 1) dp[i][j] += dp[i + 1][j]; // Downward move
                    if (j < n - 1) dp[i][j] += dp[i][j + 1]; // Rightward move
                }
            }
        }

        return dp[0][0];
    }
};