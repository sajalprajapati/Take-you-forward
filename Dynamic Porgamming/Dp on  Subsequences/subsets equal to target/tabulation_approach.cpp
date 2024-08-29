#include <vector>
#include <iostream>

using namespace std;

bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    
    // Create a 2D dp array, with dimensions (n+1) x (sum+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    
    // Initialize the first column to true because a sum of 0 can be made with an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If we don't include the current element
            dp[i][j] = dp[i-1][j];
            
            // If we include the current element (and it's less than or equal to j)
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    
    // The answer is in the bottom-right corner of the dp table
    return dp[n][sum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    
    if (isSubsetSum(arr, sum)) {
        cout << "Subset with sum " << sum << " exists." << endl;
    } else {
        cout << "No subset with sum " << sum << " exists." << endl;
    }

    return 0;
}
