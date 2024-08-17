#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> answer;

        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                answer.push_back(arr[i][j]);
            }
        }

        sort(answer.begin(),answer.end());

        return answer;
    }
};

int main()
{
    Solution sol;
    int size;
    cout<<"\n enter the value in size";
    cin>>size;
    vector<vector<int>> arr(size,vector<int> (size,0));

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<int> answer=sol.mergeKArrays(arr,size);
    for(auto it:answer)
    {
        cout<<it<<" ";
    }
}