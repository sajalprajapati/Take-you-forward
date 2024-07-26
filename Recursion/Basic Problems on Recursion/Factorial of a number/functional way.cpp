#include<bits/stdc++.h>
using namespace std;
unsigned long long int factorial_finder(unsigned long long int  number)
{
    if(number==1)
    return 1;

    return number*factorial_finder(number-1);
} 
int main()
{
    int number;
    cout<<"\n enter the number till which you need the factorial "<<endl;
    cin>>number;
    unsigned long long answer= factorial_finder(number);
    cout<<"\n the answer is "<<answer;
}