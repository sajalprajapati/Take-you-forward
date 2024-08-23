#include<bits/stdc++.h>
using namespace std;

int minimumEnergy_for_the_path(int n, vector<int> &heights) 
{  
  //step 1: Initialize dp array.
  vector<int> dp(n,-1);

  //step 2: Initialize the base case condition.
  dp[0]=0;

  //step 3:write the for loop.
  for(int i=1;i<=n;i++)
  {
    int oneLeap=dp[i-1]+abs(heights[i]-heights[i-1]);
    int twoLeap=INT_MAX;
    if(i>2)
    twoLeap=dp[i-2]+abs(heights[i]-heights[i-2]);

    //step 4:
    dp[i]=min(oneLeap,twoLeap);
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
    
    
    cout << "\nThe minimum energy required to reach the last step is " << minimumEnergy_for_the_path(n-1, heights) << endl;
}
