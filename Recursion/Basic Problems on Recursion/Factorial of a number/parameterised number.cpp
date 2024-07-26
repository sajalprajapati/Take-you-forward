#include<bits/stdc++.h>
using namespace std;
void FactorialOfSmallNumber(int i,int fact)
{
    if(i<=1)
    {
        cout<<"\n the factorial is "<<fact;
        return ;
    }

    FactorialOfSmallNumber(i-1,fact*i);
}
int main()
{
    int number;
    cout<<"\n enter the number of which you want to find the factorial of "<<endl;
    cin>>number;
    FactorialOfSmallNumber(number,1);
}