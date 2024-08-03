convertDecimal2Binary(number)#include<bits/stdc++.h>
using namespace std;
vector<int> convertDecimal2Binary(int number)
{
  vector<int> answer;

  while(number!=1)
  {
    if(number%2==1) answer.push_back(1);
    else if(number%2==0) answer.push_back(0);

    number=number/2;
  }

  answer.push_back(number);
  reverse(answer.begin(),answer.end());
  return answer;
}

int main()
{
    int number;
    cout<<"\n enter the number "<<endl;
    cin>>number;
    vector<int> answer=convertDecimal2Binary(number);
    for(auto &element:answer)
    {
        cout<<element<<" ";
    }
}