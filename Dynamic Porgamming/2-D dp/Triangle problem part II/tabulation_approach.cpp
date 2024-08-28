class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the last row of dp with the values from arr
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = arr[n-1][j];
        }    

        int bottom, left_diagonally, right_diagonally;

        // Fill the dp array from bottom to top
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                bottom = arr[i][j] + dp[i+1][j];
                
                left_diagonally = (j > 0) ? arr[i][j] + dp[i+1][j-1] : INT_MAX;
                right_diagonally = (j < n-1) ? arr[i][j] + dp[i+1][j+1] : INT_MAX;

                dp[i][j] = min(bottom, min(left_diagonally, right_diagonally));
            }
        }

        // Find the minimum value in the first row of dp
        int minimum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minimum = min(minimum, dp[0][j]);
        }

        return minimum;
    }
};
