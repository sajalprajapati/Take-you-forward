#include <bits/stdc++.h>
using namespace std;

void pickingAndNotPicking(int index, set<vector<int>> &answer, vector<int> &ds, vector<int> &originalArray, int target) {
    // Base case condition...
    if (index == originalArray.size()) {
        if (target == 0) {
            answer.insert(ds); // Add unique combination to the set
        }
        return;
    }

    // Picking the element if it is not greater than the target
    if (originalArray[index] <= target) {
        ds.push_back(originalArray[index]);
        pickingAndNotPicking(index, answer, ds, originalArray, target - originalArray[index]);
        ds.pop_back();
    }

    // Not picking the element
    pickingAndNotPicking(index + 1, answer, ds, originalArray, target);
}

vector<vector<int>> CombinationSum_partI(vector<int> &originalArray, int target) {
    set<vector<int>> answerSet;
    vector<int> data_structure;
    pickingAndNotPicking(0, answerSet, data_structure, originalArray, target);

    // Convert set to vector
    vector<vector<int>> answer(answerSet.begin(), answerSet.end());
    return answer;
}

int main() {
    vector<int> originalArray;
    int size;
    cout << "\nEnter how many elements you want to push in the vector: ";
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

    vector<vector<int>> answer = CombinationSum_partI(originalArray, target);
    cout << "The unique combinations are: " << endl;
    for (const auto &vec : answer) {
        cout << "[ ";
        for (const auto &element : vec) {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
