#include<bits/stdc++.h>
using namespace std;

void printingLinearly(int i,int number)
{
   if(i>number)
   return ;

   cout<<i<<" ";
   printingLinearly(i+1,number);
}
int main()
{
    int number;
    cout<<"\n enter how many times we have to print"<<endl;
    cin>>number;
    printingLinearly(1,number);
}