#include <iostream>
#include <vector>
using namespace std;

void findPeaksRecursive(const vector<int>& nums, int left, int right, vector<int>& peaks) {
    if (left > right) return;
    
    int mid = (left + right) / 2;
    
    // Check if mid is a peak element
    if ((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == nums.size() - 1 || nums[mid + 1] <= nums[mid])) {
        peaks.push_back(nums[mid]);
    }
    
    // Search in the left half
    findPeaksRecursive(nums, left, mid - 1, peaks);
    
    // Search in the right half
    findPeaksRecursive(nums, mid + 1, right, peaks);
}

vector<int> findPeaks(const vector<int>& nums) {
    vector<int> peaks;
    findPeaksRecursive(nums, 0, nums.size() - 1, peaks);
    return peaks;
}

int main() {
    vector<int> nums = {10, 20, 15, 2, 23, 90, 67};
    vector<int> peaks = findPeaks(nums);
    
    cout << "Peak elements are: ";
    for (int peak : peaks) {
        cout << peak << " ";
    }
    cout << endl;
    
    return 0;
}
