//this is very importanta question understand this properly.
//why we are using binary search..

#include<bits/stdc++.h>
using namespace std;
bool checker(vector<int> &stalls, int k, int middle)
{
    int cowCount = 1; // Initial cow count is 1
    int lastPosition = stalls[0]; // Position of the first cow

    for (int i = 1; i < stalls.size(); i++)
    {
        if ((stalls[i] - lastPosition) >= middle)
        {
            cowCount++; // Increment cow count
            if (cowCount == k)
            {
                return true; // Found valid distribution for all cows
            }
            lastPosition = stalls[i]; // Update last position of cow placed
        }
    }

    return false; // Could not place all cows with at least `middle` distance
}


int allocation_of_cow(vector<int> &stalls,int k)
{
    //now we are applying the binary search therfore...
    //lower value would definitely..

    /*
    agar hum unko ek hi stall se ban de ...yani difference of distance between the two cow for instance is zero..
    kyu ki cow aggressivee toh woh fight karengi par hum lower value isko hi lenge....
    ya phir lower value hum minimum of stalls distance bhi le skte hai...

    and higher jo hai woh maximum distance ;;;;
    */

   sort(stalls.begin(), stalls.end());
   int lower=0;
    int higher = stalls[stalls.size() - 1] - stalls[0]; 
   int final_answer=-1;
   while(lower<=higher)
   {
    int middle=lower+(higher-lower)/2; //this is working as the suggestion for the possible answer ..
                                    //mltb ki yeah wala difference of distance try karke dekhooo

    if(checker(stalls,k,middle))  //<----agar yeah humrha kam kar gya toh humko maximum value chahiye...therefore
                                  //<----we would move to the right
    {
        final_answer=middle;
        lower=middle+1;
    }
    else
    {
        higher=middle-1;
    }
   }

    return final_answer;
}

int main()
{
    int size;
    cout<<"\n enter the number of distance points that stall is at"<<endl;
    cin>>size;
    vector<int> stalls;
    cout<<"\n enter the value of each stall"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        stalls.push_back(element);
    }

    int Count_of_Cow;
    cout<<"\n enter the number of cows"<<endl;
    cin>>Count_of_Cow;
   
    //sort(stalls.begin(),stalls,end());

    int result=allocation_of_cow(stalls,Count_of_Cow);
    cout<<"\n the maximum difference possible for the distance is "<<result<<endl;
}