#include<bits/stdc++.h>
using namespace std;
void printingAlltheSequences(string &answerStoreHoga,string &original,int index)
{
    if(index==original.size())
    {
        cout<<"[";
        for(auto x: answerStoreHoga)
        {
          cout<<x<<" "; 
        }
        cout<<"]\n";
        return;
    }

    answerStoreHoga=answerStoreHoga+original[index];
    printingAlltheSequences(answerStoreHoga,original,index+1);

    answerStoreHoga.pop_back();
    printingAlltheSequences(answerStoreHoga,original,index+1);
}
int main()
{
    string s= "abc";
    string f="";
    printingAlltheSequences(f,s,0);
}



// #include <iostream>
// #include <vector>

// void generateSubsequences(std::vector<int>& seq, int index, std::vector<int>& subseq) {
//     if (index == seq.size()) {
//         cout << "[ ";
//         for (int x : subseq) 
//         {
//             cout << x << " ";
//         }
//         cout << "]" <<endl;
//         return;
//     }
//     // Include the current element
//     subseq.push_back(seq[index]);
//     generateSubsequences(seq, index + 1, subseq);

//     // Exclude the current element
//     subseq.pop_back();
//     generateSubsequences(seq, index + 1, subseq);
// }

// int main() {
//     std::vector<int> seq = {1, 2, 3};
//     std::vector<int> subseq;
//     generateSubsequences(seq, 0, subseq);
//     return 0;
// }
