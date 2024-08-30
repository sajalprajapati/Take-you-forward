int perfectSum(int arr[], int n, int sum)
{
     // Your code goes here
        int mod = (int)1e9+7;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        
        
        
        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
        }
        
        if (arr[0] <= sum) {
            dp[0][arr[0]] = 1;
        }
        
        if(arr[0] == 0) dp[0][0] = 2;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=sum; j++) {
                int take = 0;
                if(arr[i] <= j) {
                    take = dp[i-1][j - arr[i]];
                }
                int notTake = dp[i-1][j]; 
                
                dp[i][j] = (take + notTake) % mod;
            }
        }
        
        
        return dp[n-1][sum];
}