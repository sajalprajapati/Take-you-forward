class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<int> deq;
        vector<int> answer;

        for (int i = 0; i < n; i++)
        {
            // Remove elements that are out of this window
            while (!deq.empty() && deq.front() <= i - k)
            {
                deq.pop_front();  // Corrected this line
            }

            // Remove elements from the back while the current element is greater
            while (!deq.empty() && nums[i] >nums[deq.back()])
            {
                deq.pop_back();
            }

            // Add the current element index to the deque
            deq.push_back(i);

            // If the window has at least k elements, add the maximum to the result
            if (i >= k - 1)
            {
                answer.push_back(nums[deq.front()]);
            }
        }

        return answer;    
    }
};
