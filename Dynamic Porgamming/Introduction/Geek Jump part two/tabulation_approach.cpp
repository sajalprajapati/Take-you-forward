#include<bits/stdc++.h>
using namespace std;

int minimumEnergy_for_the_path(int n,vector<int> &heights,int k,vector<int> &dp) {
    // Base case
   //tabulation is bottom-top approach...
   dp[0]=0;

   for(int i=1;i<=n;i++)
   {
    int minimumSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
      if(i-j>=0)
      {
        int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
        minimumSteps=min(jump,minimumSteps);
        
      }
      else
      {
        break;
      }
    }
    dp[i]=minimumSteps;
   }

   return dp[n];
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
