#include<bits/stdc++.h>
using namespace std;
/*
Now we will be using the memoization technique to improve our code .....please closely look and revise the topic from the 
notebook notes that you have created .
*/

int fibo(vector<int> &dp,int n)
{
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<=n;i++)
       {
        dp[i]=dp[i-1]+dp[i-2];
       }

       return dp[n];
}
int main()
{
    int n;
    cout<<"\n enter the value of n";
    cin>>n;
    vector<int> dp(n+1,-1);
    /*
    Step 1: to declare the memory ....
    */
    cout<<"\n the value of fibonnaci at "<<n<<" "<<" is "<<fibo(dp,n);
}