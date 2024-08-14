class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n=nums.size();
        if(n==0 or n==1)
        return n;
        int count=0;
        int currentSum=0;
        for(int i=0;i<n;i++)
        {
            currentSum=0;
            for(int j=i;j<n;j++)
            {
                currentSum=currentSum+nums[j];
                if(currentSum>goal)
                break;
                else if(currentSum==goal)
                count++;                
            }
        }

        return count;    
    }
};