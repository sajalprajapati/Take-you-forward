#include<bits/stdc++.h>
using namespace std;
int SumOfN_Naturalnumber(int number)
{
    if(number==0)
    {
        return 0;
    }

    return number+SumOfN_Naturalnumber(number-1);
    
}
int main()
{
    int number;
    cout<<"\n till which you need the sum";
    cin>>number;
    int answer= SumOfN_Naturalnumber(number);
    cout<<"\n the answer is "<<answer;
}