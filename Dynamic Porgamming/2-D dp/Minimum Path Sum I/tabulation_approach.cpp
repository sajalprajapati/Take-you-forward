#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        dp[m-1][n-1] = grid[m-1][n-1];

        for (int i = m-1; i >= 0; i--) 
        {
            for (int j = n-1; j >= 0; j--) 
            {
                if (i + 1 < m) 
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i+1][j]);
                
                if (j + 1 < n) 
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};

int main()
{
    int m, n;
    cout << "\nEnter the value of m and n: " << endl;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    cout << "\nEnter the grid values: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    Solution sol;
    cout << "\nThe minimum path sum is " << sol.minPathSum(v) << endl;
}
