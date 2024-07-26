#include<bits/stdc++.h>
using namespace std;
void SumOfN_Naturalnumber(int number,int sum)
{
    if(number==0)
    {
        cout<<"\n the sum of the natural number till the value you entered is "<<sum;
        return;
    }

    SumOfN_Naturalnumber(number-1,sum+number);
    
}
int main()
{
    int number;
    cout<<"\n till which you need the sum";
    cin>>number;
    SumOfN_Naturalnumber(number,0);
}