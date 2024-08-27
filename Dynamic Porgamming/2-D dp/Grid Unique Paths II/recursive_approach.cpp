#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& arr)
    {
        // Base cases
        if (i >= m || j >= n || arr[i][j] == 1) 
            return 0;  // Out of bounds or obstacle

        if (i == m-1 && j == n-1)
            return 1;  // Reached the bottom-right corner

        // Recursive calls for right and bottom moves
        int right = helper(i, j + 1, m, n, arr);
        int bottom = helper(i + 1, j, m, n, arr);

        return right + bottom;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting or ending point is blocked, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

       
        return helper(0, 0, m, n, obstacleGrid);
    }
};

int main()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    cout << "The total number of unique paths is " << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
}
