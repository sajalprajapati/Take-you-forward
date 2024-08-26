#include<bits/stdc++.h>
using namespace std;
int maximumNonAdjacentElements(vector<int> &v,int index)
{
    if(index==0) return v[index];
    if(index<0) return 0;
    int pick=v[index]+maximumNonAdjacentElements(v,index-2);
    int notpick=0+maximumNonAdjacentElements(v,index-1);

    return max(pick,notpick);
}
int main()
{
    int size;
    cout<<"\n enter the size of the vector"<<endl;
    cin>>size;

    vector<int> v;
    cout<<"\n enter the elements in the vector"<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

   cout<<"\n the maximum element is "<<maximumNonAdjacentElements(v,size-1);

}