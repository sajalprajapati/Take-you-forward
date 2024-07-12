#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int> &nums, int middle, int k) {
    int k_count = 1;
    int subarray_sum = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        if (subarray_sum + nums[i] <= middle) {
            subarray_sum += nums[i];
        } else {
            k_count++;
            if (k_count > k) {
                return false;
            }
            subarray_sum = nums[i];
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int k) {
    int lower = *max_element(nums.begin(), nums.end());
    int higher = accumulate(nums.begin(), nums.end(), 0);
    int answer = higher;

    while (lower <= higher) {
        int middle = lower + (higher - lower) / 2;

        if (checker(nums, middle, k)) {
            answer = middle;
            higher = middle - 1;
        } else {
            lower = middle + 1;
        }
    }

    return answer;
}

int main() {
    int array_size;
    cout << "Enter the size of nums: ";
    cin >> array_size;

    int k;
    cout << "Enter how many divisions you want to make: ";
    cin >> k;

    if (k > array_size) {
        cout << "This division is not allowed." << endl;
        return 0;
    }

    vector<int> nums;
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < array_size; i++) {
        int element;
        cin >> element;
        nums.push_back(element);
    }

    int result = splitArray(nums, k);
    cout << "The minimum maximum sum of subarrays is: " << result << endl;

    return 0;
}
