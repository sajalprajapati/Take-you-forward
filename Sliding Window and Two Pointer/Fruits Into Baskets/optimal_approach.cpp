#include<bits/stdc++.h>
using namespace std;
//it is using the sliding window technique.
int totalFruits(vector<int> &arr)
{
    int n=arr.size();
    if(n==0 or n==1)
    return n;

    int maxLength=0;
    int left=0;
    int right=0;
    unordered_map<int,int> mali_ki_tokri;

    while(right<n)
    {
        mali_ki_tokri[arr[right]]++; //mali ki torik main sabse pehle daalo fruit kyu ki woh check karke btyaega ki do se jyada fal hai ya nhi.....

        //woh kaise check karega ..iska procedure ...
        if(mali_ki_tokri.size()>2)
        {
            mali_ki_tokri[arr[left]]--;
            if(mali_ki_tokri[arr[left]]==0) mali_ki_tokri.erase(arr[left]);
            left++;           
        }

        //jab malike ne kaha do type se jayda fal nhi hai ...tab ...

        else if(mali_ki_tokri.size()<=2)
        {
            maxLength=max(maxLength,right-left+1);
        }
        right++;
    }

    return maxLength;
}
int main()
{
   vector<int> arr;
   int size;
   cout<<"\n enter the size of the vector";
   cin>>size;
   cout<<"\n enter the elements in the vector"<<endl;
   for(int i=0;i<size;i++)
   {
    int element;
    cin>>element;
    arr.push_back(element);
   }
   
   cout<<"\n the length is "<<totalFruits(arr);
}