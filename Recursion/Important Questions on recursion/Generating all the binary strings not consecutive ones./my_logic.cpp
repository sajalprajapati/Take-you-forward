#include<bits/stdc++.h>
using namespace std;
void allBinaryStringsWithoutConsecutiveOnes(string str,vector<string> &answer,int k)
{
     if(k==0)
     {
        answer.push_back(str);
        return ;
     }

     allBinaryStringsWithoutConsecutiveOnes(str + "0",answer,k-1); //this one is for all 0's generation;

     if(str.empty() || str.back()!='1')
     {
        allBinaryStringsWithoutConsecutiveOnes(str+"1",answer,k-1);
     }
}

int main()
{
    int k;
    cout<<"\n enter the value of k";
    cin>>k;

    vector<string> answer ;
    //string str;
    allBinaryStringsWithoutConsecutiveOnes("",answer,k);
    for( const auto &element:answer)
    {
        cout<<"[";
        cout<<element;
        cout<<"]";
    }
}