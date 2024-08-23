#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n<=1)
    return n;

    return fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    cout<<"\n enter the value of n";
    cin>>n;
    cout<<"\n the value of fibonnaci at "<<n<<" "<<" is "<<fibo(n);
}