#include<bits/stdc++.h>
using namespace std;

int minimumEnergy_for_the_path(int n, vector<int> &heights) {
    // Base case
    if (n == 0) return 0;
    if (n == 1) return abs(heights[1] - heights[0]);

    // Recursively calculate the minimum energy
    int left = minimumEnergy_for_the_path(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX; // Initialize to a large value

    if (n > 1) {
        right = minimumEnergy_for_the_path(n-2, heights) + abs(heights[n] - heights[n-2]);
    }

    return min(left, right);
}

int main() {
    int n;
    cout << "\nEnter the value of n: ";
    cin >> n;
    vector<int> heights(n);

    cout << "\nEnter the value of energies at different heights: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << "\nThe minimum energy required to reach the last step is " << minimumEnergy_for_the_path(n-1, heights) << endl;
}
