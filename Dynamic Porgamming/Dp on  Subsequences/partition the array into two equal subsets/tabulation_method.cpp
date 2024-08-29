class Solution {
public:
    bool subsetEqualtoSum(vector<int>& nums,int target)
    {
        // int n=nums.size();
        // vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

        // for(int i=0;i<n;i++)
        // {
        //     dp[i][0]=true;
        // }

        // dp[0][nums[0]]=true;

        // for(int i=1;i<n;i++)
        // {
        //     for(int j=1;j<=target;j++)
        //     {
        //         bool notTake=dp[i-1][j];
        //         bool take=false;
        //         if(j>=nums[i])
        //         {
        //             take=dp[i-1][j-nums[i]];
        //         }

        //         dp[i][j]=notTake or take;
        //     }
        // }

        // return dp[n-1][target];

         int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: A sum of 0 can always be achieved with an empty subset
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Base case: If the sum is exactly the first element
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (j >= nums[i]) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = notTake || take;
            }
        }

        return dp[n - 1][target];
    }

    
    bool canPartition(vector<int>& nums) 
    {
      int total_sum=0;
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
        total_sum=total_sum+nums[i];
      }    

      if(total_sum%2!=0) return false;
      int target=total_sum/2;

      return subsetEqualtoSum(nums,target);
    }
};