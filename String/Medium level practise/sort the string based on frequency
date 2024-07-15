#include<bits/stdc++.h>
using namespace std;
string checker(string s)
{
    vector<pair<char,int>> vec(123);

    //we will be calculating the frequency 
    for(auto &ch : s)
    {
        int frequency = vec[ch].second;
        vec[ch]={ch,frequency+1};
    } 

    auto lambda =[&](pair<char,int> &P1 , pair<char,int> &P2)
    {
        return P1.second>P2.second;
    };

    sort(vec.begin(),vec.end(),lambda);

    string result="";

    for(int i=0;i<=122;i++)
    {
        if(vec[i].second>0)
        {
            char ch=vec[i].first;
            int freq=vec[i].second;
            string temp=string(freq,ch);

            result+=temp;
        }
    }

    return result;


}
int main()
{
    string s;
    cout<<"\n enter the string "<<endl;
    cin>>s;

    string answer=checker(s);
    cout<<"\n the string is "<<answer<<endl;
}