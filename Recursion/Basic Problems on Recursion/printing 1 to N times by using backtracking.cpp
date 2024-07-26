#include<bits/stdc++.h>
using namespace std;
void backTrackingLinearlyTraversing(int number)
{
    if(number==0)
    return ;

    backTrackingLinearlyTraversing(number-1);
    cout<<number<<" ";
}
int main()
{
    int number;
    cout<<"\n enter how many times want to print the number";
    cin>>number;
    backTrackingLinearlyTraversing(number);
}