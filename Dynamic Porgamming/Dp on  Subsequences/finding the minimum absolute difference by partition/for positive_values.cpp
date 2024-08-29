class Solution {
public:
    int minimumDifference(vector<int>& nums) 
    {
       int n = nums.size(); 
       int totalSum = 0;
       for(int i = 0; i < n; i++)
       {
           totalSum += nums[i];
       }    

       vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
       
       // Initialize dp[j][0] = true for all j, since target 0 can always be achieved
       for(int j = 0; j < n; j++)
       {
           dp[j][0] = true;
       }

       // Base case: if nums[0] is less than or equal to totalSum
       if(nums[0] <= totalSum)
       {
           dp[0][totalSum] = true;
       }

       // Fill the dp table
       for(int row = 1; row < n; row++)
       {
           for(int target = 1; target <= totalSum; target++)
           {
               // not pick case
               bool notpick = dp[row - 1][target];

               // pick case
               bool pick = false;
               if(nums[row] <= target)
               {
                   pick = dp[row - 1][target - nums[row]];
               }

               dp[row][target] = notpick || pick;
           }
       } 

       // Find the minimum difference
       int minimum = 1e9;
       for(int i = 0; i <= totalSum / 2; i++)
       {
           if(dp[n - 1][i] == true)
           {
               minimum = min(minimum, abs((totalSum - i) - i));
           }
       }
       return minimum;
    }
};
