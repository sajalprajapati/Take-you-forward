#include<bits/stdc++.h>
using namespace std;
int convertBinary2Decimal(vector<int> bits)
{
  int size=bits.size();
  int number=0;
  int n=size-1;
  for(int i=0;i<size;i++)
  {
     number=number+(bits[i]*pow(2,((n-i))));
  }
  return number;
}

int main()
{
  vector<int> bits;
  int element;
  while(cin>>element)
  {
    bits.push_back(element);
  }  

  int number =convertBinary2Decimal(bits);
  cout<<"\n the number is "<<number;
}