class Solution {
public:
    //we will be determining how many subarray would have sum equal to and less than goal
    int counting(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;

        int n=nums.size();
        int left=0,right=0,count=0,sum=0;

        while(right<n)
        {
            sum=sum+nums[right];
            //two possiblities can be possible:
            //first possibilities : sum>goal
            while(sum>goal)
            {
                sum=sum-nums[left];
                left++;
            }

            //first possibilities : sum<=goal
            if(sum<=goal)
            {
                count=count+(right-left+1);
            }
            right++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
           return counting(nums,goal)-counting(nums-(goal-1));
    }
};