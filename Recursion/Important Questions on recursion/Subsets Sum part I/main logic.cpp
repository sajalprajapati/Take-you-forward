#include<bits/stdc++.h>
using namespace std;
void mainLogic(int index,vector<int> &answer, vector<int> &originalArray,int sum)
{
    //base case condition
    if(index==originalArray.size())
    {
        answer.push_back(sum);
        return ;
    }

    mainLogic(index+1,answer,originalArray,sum+originalArray[index]);
    mainLogic(index+1,answer,originalArray,sum);
    
}
vector<int> subsets_SumI(vector<int> &originalArray)
{
    vector<int> answer;
    mainLogic(0,answer,originalArray,0);
    sort(answer.begin(),answer.end());
    return answer;;
}
int main()
{
    vector<int> originalArray;
    cout<<" \n Enter the elements in the originalArray . Press 'Ctrl+D' when you entering the elements";
    int element;
    while(cin>>element)
    {
       originalArray.push_back(element);
    }
    // cout<<"sgsgfrs";

    vector<int> result=subsets_SumI(originalArray);
    for(auto element:result)
    {
        cout<<element<<" ";
    }
    return 0;
}