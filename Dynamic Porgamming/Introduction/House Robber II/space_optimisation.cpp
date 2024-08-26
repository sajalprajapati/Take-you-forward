
#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int> &arr) {
    int n = arr.size();
    
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int previous = arr[0];
    int previous2 = 0;

    for (int i = 1; i < n; ++i) {
        int take = arr[i];
        if (i > 1) take += previous2;

        int notTake = previous;

        int current = max(take, notTake);

        previous2 = previous;
        previous = current;
    }
    return previous;
}

int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> temp1(nums.begin() + 1, nums.end()); // Exclude the first house
    vector<int> temp2(nums.begin(), nums.end() - 1); // Exclude the last house

    return max(maximumSum(temp1), maximumSum(temp2));
}

int main() {
    int size;
    cout << "\nEnter the size of the vector: ";
    cin >> size;

    vector<int> nums(size);
    cout << "\nEnter the elements in the vector: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    cout << "Maximum amount robbed is: " << rob(nums) << endl;

    return 0;
}
