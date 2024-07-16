#include<bits/stdc++.h>
using namespace std;
static vector<int> val{5000,4000,1000,900,500,400,100,90,50,40,10,9,5,4,1};
static vector<string> sym{"V`","IV`","M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
string IntegerToRoman(int num)
{
    string answer="";

    for(int i=0;i<15;i++)
    {
        if(num==0)
        break;

        int times=num/val[i];

        while(times--)
        {
            answer+=sym[i];
        }

        num=num%val[i];
    }

    return answer;
}
int main()
{
    int number;
    cout<<"\n enter the number "<<endl;
    cin>>number;
    string roman=IntegerToRoman(number);
    cout<<"\n the roman number is "<<roman<<endl;
}