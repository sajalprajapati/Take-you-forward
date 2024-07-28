#include <bits/stdc++.h>
using namespace std;

void picking(int index, vector<vector<int>> &answer, vector<int> &ds, vector<int> &originalArray, int target) {
    // Base condition:
    if (target == 0) {
        answer.push_back(ds);
        return;
    }

    for (int i = index; i < originalArray.size(); i++) {
        if (i > index && originalArray[i] == originalArray[i - 1]) continue; // Skip duplicates
        if (originalArray[i] > target) break; // No need to proceed further

        ds.push_back(originalArray[i]);
        picking(i + 1, answer, ds, originalArray, target - originalArray[i]);
        ds.pop_back();
    }
}

vector<vector<int>> CombinationSum_partII(vector<int> &originalArray, int target) {
    vector<vector<int>> answer;
    vector<int> data_structure;
    sort(originalArray.begin(), originalArray.end()); // Sort the array to handle duplicates
    picking(0, answer, data_structure, originalArray, target);
    return answer;
}

int main() {
    vector<int> originalArray;
    int size;
    cout << "Enter how many elements you want to push in the vector: ";
    cin >> size;

    cout << "Enter the elements in the vector: ";
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        originalArray.push_back(element);
    }

    int target;
    cout << "Please enter your target value: ";
    cin >> target;

    vector<vector<int>> answer = CombinationSum_partII(originalArray, target);

    cout << "The combinations are: " << endl;
    for (const auto &vec : answer) {
        cout << "[ ";
        for (const auto &element : vec) {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
