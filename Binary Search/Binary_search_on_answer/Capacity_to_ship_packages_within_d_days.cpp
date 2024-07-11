#include<bits/stdc++.h>
using namespace std;
int findDays(vector<int> &weights,int capacity)
{
  int day=1;
  int load=0;
  int size=weights.size();

  for(int i=0;i<size;i++)
  {
    if(load+weights[i]>capacity)
    {
        load=weights[i];
        day+=1;
    }

    else
    {
        load+=weights[i];
    }
  }

  return day;
}
int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
}


int main()
{
    int size;
    cout<<"\n enter how many weights would like to transfer"<<endl;
    cin>>size;
    vector<int> weights;
    cout<<"\n enter the number of weights"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        weights.push_back(element);
    }

    int d;
    cout<<"\n enter in how many days you want to transfer the packages"<<endl;
    cin>>d;

    int answer=leastWeightCapacity(weights,d);
    cout<<"\n the number of days will be "<<answer;
}