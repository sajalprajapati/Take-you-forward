#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
   int previous=1;
   int previous2=0;
   for(int i=2;i<=n;i++)
   {
    int current=previous+previous2;
    previous2=previous;
    previous=current;
   }  

   return previous;
}
int main()
{
    int n;
    cout<<"\n enter the value of n";
    cin>>n;
    cout<<"\n the value of fibonnaci at "<<n<<" "<<" is "<<fibo(n);
}