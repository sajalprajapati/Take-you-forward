class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int lsum=0,rsum=0,maxSum=0;

        for(int i=0;i<k;i++)
        {
            lsum=lsum+cardPoints[i];
            maxSum=max(maxSum,lsum);
        }

        int rightIndex=cardPoints.size()-1;
        for(int j=k-1;j>=0;j--)
        {
            lsum=lsum-cardPoints[j];
            rsum=rsum+cardPoints[rightIndex];
            rightIndex=rightIndex-1;

            maxSum=max(maxSum,lsum+rsum);
        }

        return maxSum;
    }
};