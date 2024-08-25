#include<bits/stdc++.h>
using namespace std;

int minimumEnergy_for_the_path(int n,vector<int> &heights,int k,vector<int> &dp) {
    // Base case
    if (n == 0) return 0;

     
    if(dp[n]!=-1) return dp[n];

    int minimumSteps=INT_MAX; 
    for(int i=1;i<=k;i++)
    {
     if(n-i>=0)   
     {
        int jump=minimumEnergy_for_the_path(n-i,heights,k,dp)+abs(heights[n]-heights[n-i]);
        minimumSteps=min(jump,minimumSteps);
     }
     else
     {
        break;
     }
    }    

    return dp[n]=minimumSteps;
}

int main() {
    int n;
    cout << "\nEnter the value of n: ";
    cin >> n;
    vector<int> heights(n);

    cout << "\nEnter the value of energies at different heights: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int k;
    cout<<"\n enter the value of k";
    cin>>k;

     //apni memory baneani padegiiii.
     vector<int> dp(n,-1);
    cout << "\nThe minimum energy required to reach the last step is " << minimumEnergy_for_the_path(n-1, heights,k,dp) << endl;
}
