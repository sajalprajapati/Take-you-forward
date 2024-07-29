#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) 
{
   double answer=1.0;
   long long nn=n;
   if(nn<0) nn=-1*nn;
   while(nn)
   {
    if(nn%2)
    {
      answer=answer*x;
      nn=nn-1; 
    }
    
    else if(nn%2==0)
    {
        x=x*x;
        nn=nn/2;
    }
   }
   
   if(n<0) answer=(double)(1.0)/(double)(answer);
   return answer;
}
int main()
{
    cout<<myPow(2.0000000,10);
}