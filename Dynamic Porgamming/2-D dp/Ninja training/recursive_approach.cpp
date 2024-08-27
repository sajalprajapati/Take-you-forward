#include<bits/stdc++.h>
using namespace std;
int helper(vector<vector<int>>& arr,int day,int lastdayactivity)
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


    int maximum=0;
    for(int i=0;i<=2;i++)
    {
        int points=arr[day][i]+helper(arr,day-1,i);
        maximum=max(maximum,points);
    }

    return maximum;
}
 int maximumPoints(vector<vector<int>>& arr, int n) 
 {
        return helper(arr,arr.size()-1,3);
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