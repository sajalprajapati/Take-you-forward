#include<bits/stdc++.h>
using namespace std;

void printingLinearly(int number)
{
   if(number==0)
   return ;

   cout<<number<<" ";
   number=number-1;
   printingLinearly(number);
}
int main()
{
    int number;
    cout<<"\n enter how many times we have to print"<<endl;
    cin>>number;
    printingLinearly(number);
}