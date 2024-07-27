#include<bits/stdc++.h>
using namespace std;
void printingAlltheSequences(vector<int> &answerStoreHoga,vector<int> &original,int index)
{
    if(index==original.size())
    {
        cout<<"[";
        for(auto x: answerStoreHoga)
        {
          cout<<x<<" "; 
        }
        cout<<"]";
    }

    answerStoreHoga.push_back(original[index]);
    printingAlltheSequences(answerStoreHoga,original,index+1);

    answerStoreHoga.pop_back();
    printingAlltheSequences(answerStoreHoga,original,index+1);
}
int main()
{
    vector<int> seq = {1, 2, 3};
    vector<int> subseq;
    printingAlltheSequences(subseq,seq,0);
}

