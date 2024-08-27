#include<bits/stdc++.h>
using namespace std;
int helper(vector<vector<int>>& arr,int day,int lastdayactivity,vector<vector<int>> &dp)
{
    if(day==0)
    {
        int maximumSum=0;
        for(int i=0;i<3;i++)
        {
            if(i!=lastdayactivity)
            {
                maximumSum=max(maximumSum,arr[day][i]);
            }
        }

        return maximumSum;
    }

    if(dp[day][lastdayactivity]!=-1) return dp[day][lastdayactivity];

    int maximum=0;
    for(int i=0;i<=2;i++)
    {
        int points=arr[day][i]+helper(arr,day-1,i,dp);
        maximum=max(maximum,points);
    }

    return dp[day][lastdayactivity]= maximum;
}


 int maximumPoints(vector<vector<int>>& arr, int n) 
{
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return helper(arr,arr.size()-1,3,dp);
}



int main()
{
    int size;
    cout<<"\n enter the size of the vector"<<endl;
    cin>>size;

    vector<vector<int>> v(size, vector<int>(size));

    cout << "\nEnter the elements in the vector:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> v[i][j];
        }
    }

    cout<<"\n the maximum it can perform is "<<maximumPoints(v,size);
}