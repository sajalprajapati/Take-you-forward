#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Initialize dp for the first day
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

    for (int day = 1; day < n; day++) {
        for (int lastdayactivity = 0; lastdayactivity < 4; lastdayactivity++) {
            dp[day][lastdayactivity] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != lastdayactivity) {
                    int points = arr[day][task] + dp[day-1][task];
                    dp[day][lastdayactivity] = max(points, dp[day][lastdayactivity]);
                }
            }
        }
    }

    return dp[n-1][3];
}

int maximumPoints(vector<vector<int>>& arr, int n) {
    return helper(arr);
}

int main() {
    int size;
    cout << "\nEnter the number of days: ";
    cin >> size;

    // Assuming there are always 3 activities
    vector<vector<int>> v(size, vector<int>(3));

    cout << "\nEnter the points for each activity on each day:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    cout << "\nThe maximum points Geek can achieve is: " << maximumPoints(v, size) << endl;

    return 0;
}
