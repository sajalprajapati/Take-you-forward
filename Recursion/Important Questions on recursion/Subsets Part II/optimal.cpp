#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) 
    {
        ans.push_back(ds);

        for (int i = index; i < arr.size(); i++) 
        {
            if (i > index && arr[i] == arr[i - 1]) continue; // Skip duplicates
            ds.push_back(arr[i]);
            f(i + 1, arr, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& candidates) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        f(0, candidates, ds, ans);
        return ans;
    }
};

int main() 
{
    vector<int> candidates;
    int size;
    cout << "Enter the number of elements in the vector: ";
    cin >> size;
    cout << "Enter the elements in the vector: ";
    for (int i = 0; i < size; ++i) 
    {
        int element;
        cin >> element;
        candidates.push_back(element);
    }

    Solution sol;
    vector<vector<int>> result = sol.subsetsWithDup(candidates);

    cout << "The unique combinations are: " << endl;
    for (const auto& subset : result) 
    {
        cout << "[ ";
        for (const auto& element : subset) 
        {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
