#include<bits/stdc++.h>
using namespace std;
/*
Now we will be using the memoization technique to improve our code .....please closely look and revise the topic from the 
notebook notes that you have created .
*/

int fibo(vector<int> &dp,int n)
{
    if(n<=1)
    return n;
    
    if(dp[n]!=-1) return dp[n]; //Step 3: hum apni memory main jakar deka ki koi value toh present nhi hai,kyu ki agar hui toh smjh lena ki humne usse part ke liye woh pehle se solve kar rkha hai...
    
    //<-----this is our step 2..becoz if in memory we haven't solved the sub problem then we goona store it for the futer part.
    return dp[n]=fibo(dp,n-1)+fibo(dp,n-2);  
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