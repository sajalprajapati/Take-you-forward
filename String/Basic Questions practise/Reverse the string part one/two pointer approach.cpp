#include<bits/stdc++.h>
using namespace std;
string reversalOftheString(string s) 
{
    //Step 1: Reverse the whole string...
    reverse(s.begin(),s.end()); //this will reverse the whole string...

    //Step 2:Checking for the character and space present in the string s.
    int sizeOfString=s.size();
    int i=0 ;//this will check whether the character present at that index is alphabet or space. 
    int l=0;// this will help in reversing the string .
    int r=0;// this will help in reversing the string .

    while(i<sizeOfString)
    {
        while(i<sizeOfString and s[i]!=' ') //this case is handling when the s[i] is countering alphabet...
        {
            s[r]=s[i];
            i++;
            r++;
        }

        if(l<r)
        {
            reverse(s.begin()+l,s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
        }

       i++; 
    }

    return s.substr(0,r-1);
}

int main()
{
    string s;
    cout<<"\n enter your string "<<endl;
    getline(cin,s);
    string result=reversalOftheString(s);
    cout<<"\n the string after removing the outermost paranthesis is"<<endlsk<<result<<endl;
}