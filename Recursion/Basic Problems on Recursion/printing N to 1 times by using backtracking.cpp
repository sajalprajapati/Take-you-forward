#include<bits/stdc++.h>
using namespace std;
void backTrackingLinearlyTraversing(int number,int i)
{
    if(number<i)
    return ;

    backTrackingLinearlyTraversing(number,i+1);
    cout<<i<<" ";
}
int main()
{
    int number;
    cout<<"\n enter how many times want to print the number";
    cin>>number;
    backTrackingLinearlyTraversing(number,1);
}