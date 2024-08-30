#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int helper(int index, int givenSum, vector<int>& arr, vector<vector<int>>& dp)
{
    if (index == 0)
    {
        if (arr[0] == 0 && givenSum == 0) return 2; // Case when both sum and first element are 0.
        if (givenSum == 0) return 1;               // Subset with sum 0 (empty subset).
        if (arr[0] == givenSum) return 1;          // Subset with sum equal to the first element.
        return 0;
    }

    if (dp[index][givenSum] != -1) return dp[index][givenSum];

    int notTake = helper(index - 1, givenSum, arr, dp) % MOD;
    int take = 0;
    if (givenSum >= arr[index])
    {
        take = helper(index - 1, givenSum - arr[index], arr, dp) % MOD;
    }

    return dp[index][givenSum] = (take + notTake) % MOD;
}

int perfectSum(vector<int>& arr, int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return helper(n - 1, sum, arr, dp) % MOD;
}

int countPartitions(int n, int d, vector<int>& arr) 
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0); 

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
