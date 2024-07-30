#include <bits/stdc++.h>
using namespace std;

void picking(int index, vector<vector<string>> &answer, vector<string> &ds, vector<string> &originalArray, set<vector<string>> &uniqueSubsequences) {
    if (index == originalArray.size()) {
        if (!ds.empty() && uniqueSubsequences.find(ds) == uniqueSubsequences.end()) {
            uniqueSubsequences.insert(ds);
            answer.push_back(ds);
        }
        return;
    }

    // Include the current element
    ds.push_back(originalArray[index]);
    picking(index + 1, answer, ds, originalArray, uniqueSubsequences);
    ds.pop_back();

    // Exclude the current element and move to the next
    picking(index + 1, answer, ds, originalArray, uniqueSubsequences);
}

vector<vector<string>> uniqueSubsequences(vector<string> &originalArray) {
    vector<vector<string>> answer;
    vector<string> data_structure;
    set<vector<string>> uniqueSubsequences;
    // sort(originalArray.begin(), originalArray.end()); // Sort the array to handle duplicates
    picking(0, answer, data_structure, originalArray, uniqueSubsequences);
    return answer;
}

int main() {
    vector<string> originalArray;
    int size;
    cout << "Enter how many elements you want to push in the vector: ";
    cin >> size;

    cout << "Enter the elements in the vector: ";
    for (int i = 0; i < size; i++) {
        string element;
        cin >> element;
        originalArray.push_back(element);
    }

    vector<vector<string>> answer = uniqueSubsequences(originalArray);

    cout << "The unique subsequences are: " << endl;
    for (const auto &vec : answer) {
        cout << "[ ";
        for (const auto &element : vec) {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
