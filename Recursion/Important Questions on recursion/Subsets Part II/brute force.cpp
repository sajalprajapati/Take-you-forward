#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, vector<int>& arr,vector<int>& ds, set<vector<int>>& ans) {
        // BASE CASE
        if (i == arr.size()) 
        {
            ans.insert(ds);
            return;
        }

        // RECURRENCE RELATION
        
            ds.push_back(arr[i]);
            f(i + 1, arr,ds, ans);
            ds.pop_back();
        
        f(i + 1, arr, ds, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
        vector<int> ds;
        set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        f(0, candidates,ds, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main() {
    vector<int> candidates;
    int size;
    cout << "Enter the number of elements in the vector: ";
    cin >> size;
    cout << "Enter the elements in the vector: ";
    for (int i = 0; i < size; ++i) {
        int element;
        cin >> element;
        candidates.push_back(element);
    }

    // int target;
    // cout << "Enter the target value: ";
    // cin >> target;

    Solution sol;
    vector<vector<int>> result = sol.subsetsWithDup(candidates);
    
    cout << "The unique combinations are: " << endl;
    for (const auto& vec : result) {
        cout << "[ ";
        for (const auto& element : vec) {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
