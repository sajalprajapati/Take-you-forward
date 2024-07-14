#include <bits/stdc++.h>
using namespace std;

string odd_integer(string s) 
{
   int size=num.size();

      for(int i=size-1;i>=0;i--)
      {
        if((num[i]-'0')%2==1)
        {
            return num.substr(0,i+1);
        }
      }
      return "";  
}

int main() {
    string s;
    cout << "\nEnter the number: ";
    cin >> s;

    cout << "\nThe largest odd integer is: " << odd_integer(s) << endl;
}
