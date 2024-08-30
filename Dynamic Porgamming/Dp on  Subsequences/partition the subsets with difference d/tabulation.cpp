#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int perfectSum(vector<int>& arr, int n, int givensum)
{
    vector<vector<int>> dp(n, vector<int>(givensum + 1, 0));

    // Initializing dp array
    for (int row = 0; row < n; row++) {
        dp[row][0] = 1;  // There's always one subset (empty) with sum 0
    }

    // Handle the first element separately
    if (arr[0] != 0 && arr[0] <= givensum)
        dp[0][arr[0]] = 1;

    if (arr[0] == 0) 
        dp[0][0] = 2;  // Either pick the zero element or not

    // Fill the dp array
    for (int row = 1; row < n; row++) {
        for (int target = 0; target <= givensum; target++) {
            int take = 0;
            if (arr[row] <= target) {
                take = dp[row - 1][target - arr[row]];
            }

            int notTake = dp[row - 1][target];

            dp[row][target] = (take + notTake) % MOD;
        }
    }

    return dp[n - 1][givensum];
}

int countPartitions(int n, int d, vector<int>& arr) 
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0); 

    // Check if the partition is possible
    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0) return 0;

    int targetSum = (totalSum - d) / 2;

    return perfectSum(arr, n, targetSum);
}

int main()
{
    int size;
    cout << "\nEnter the size of the array: ";
    cin >> size;
    
    vector<int> v(size);
    cout << "\nEnter the elements in the array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int d;
    cout << "\nEnter the value of d: ";
    cin >> d;

    cout << "\nThe total number of subsets are: " << countPartitions(size, d, v) << endl;

    return 0;
}
