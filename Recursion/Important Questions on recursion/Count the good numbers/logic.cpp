#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
unsigned long long modPow(long long base,long long exponent,unsigned long long MOD)
{
 int result=1;
 while(exponent!=0)
 {
    if(exponent%2==1)
    {
        result=(result*base)%MOD;
    }

    base=(base*base)%MOD;
    exponent/=2;
 }

 return result;
}

unsigned long long countGoodNumber(long long number)
{
    unsigned long  long evenPositions=(number+1)/2;
    unsigned long long oddPositions=(number)/2;

    unsigned long  long evenCount=modPow(5,evenPositions,mod);
    unsigned long  long oddCount=modPow(4,oddPositions,mod);

    return (evenCount*oddCount)%mod;
}
int main()
{
    long long  number;
    cout<<"\n enter how many digits number have to be counted for good numbers";
    cin>>number;
    unsigned long long answer=countGoodNumber(number);
    cout<<"\n the answer is "<<answer;
}