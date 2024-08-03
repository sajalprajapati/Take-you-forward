#include<bits/stdc++.h>
using namespace std;
void swapping(int &a,int &b)
{
    a=(a^b);
    b=(a^b);
    a=(a^b);
}
int main()
{
    int a=5,b=7;
    swapping(a,b);
    cout<<a<<" "<<b;
}