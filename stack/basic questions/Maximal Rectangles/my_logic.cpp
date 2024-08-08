class Solution 
{
public:
    vector<int> previousSmallerElementIndices(vector<int> &heights,int n)
    {
        vector<int> answer(n);
        stack<int> stk;

        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() and heights[i] <= heights[stk.top()])
            {
                stk.pop();
            }
            answer[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        return answer;
    }

    vector<int> nextSmallerElementIndices(vector<int> &heights,int n)
    {
        vector<int> answer(n);
        stack<int> stk;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!stk.empty() and heights[i] <= heights[stk.top()])
            {
                stk.pop();
            }
            answer[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        return answer;
    }

    int getMaxArea(vector<int>& heights) 
    {
        int res = 0;
        int n = heights.size();
        vector<int> previousSmallerElement = previousSmallerElementIndices(heights, n);
        vector<int> nextSmallerElement = nextSmallerElementIndices(heights, n);

        for(int i = 0; i < n; i++)
        {
            int totalNo_Of_bars = (nextSmallerElement[i] - previousSmallerElement[i]) - 1;
            int totalarea_Of_a_bar = heights[i] * totalNo_Of_bars;
            res = max(res, totalarea_Of_a_bar); 
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        // Check for empty matrix
        if(matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> summation(n, 0);
    
        // Initialize the summation vector with the first row values
        for(int i = 0; i < n; i++)
        {
            summation[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = getMaxArea(summation);

        // Iterate through the rest of the rows
        for(int row = 1; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                // Update the summation vector based on the current row
                summation[col] = (matrix[row][col] == '0') ? 0 : summation[col] + 1;
            }

            maxArea = max(maxArea, getMaxArea(summation));
        }

        return maxArea;    
    }
};
