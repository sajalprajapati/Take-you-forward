#include<bits/stdc++.h>
using namespace std;
bool helper(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
    // Base cases
    if (target == 0) return true;
    if (index == arr.size() || target < 0) return false;

    // Check if the solution is already computed
    if (dp[index][target] != -1) return dp[index][target];

    // Not pick condition
    if (helper(index + 1, target, arr, dp)) return dp[index][target] = true;

    // Pick condition
    if (target >= arr[index]) {
        if (helper(index + 1, target - arr[index], arr, dp)) return dp[index][target] = true;
    }

    return dp[index][target] = false;
}

bool isSubsetSum(vector<int> arr, int sum) {
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1)); // Use -1 for uninitialized values
    return helper(0, sum, arr, dp);
}


int main()
{
    int size;
    cout<<"\n enter the size of the vector"<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        arr.push_back(element);
    }

    int target;
    cout<<"\n enter the target value"<<endl;
    cin>>target;

    bool answer=isSubsetSum(arr,target);
    if(answer==true)
    cout<<"\n yes"<<endl;
    else
    cout<<"\n no"<<endl;
}