#include <bits/stdc++.h>
using namespace std;

void permutationLogic(vector<int> &nums, vector<vector<int>> &answer,int index) {
    if (index==nums.size()) {
        answer.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) 
    {
      swap(nums[index],nums[i]);
      permutationLogic(nums,answer,index+1);
      swap(nums[index],nums[i]);    
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> answer;
    vector<int> ds;
    // vector<int> frequency(nums.size(), 0);  // Use a vector to keep track of frequency
    permutationLogic(nums, answer,0);
    return answer;
}

int main() {
    vector<int> originalArray;
    cout << "\nEnter the elements in the original Array (end input with a non-integer): ";
    int element;
    while (cin >> element) {
        originalArray.push_back(element);
    }
    cin.clear(); // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input

    vector<vector<int>> answer = permute(originalArray);
    for (const auto &permutation : answer) {
        cout << "[";
        for (const auto &num : permutation) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
