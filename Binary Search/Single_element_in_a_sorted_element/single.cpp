//single-mingle problem ....
//it is a real life problem...
//we have to find which pair is single in the given group.
#include<bits/stdc++.h>
using namespace std;


int single(vector<int> &v)
{ 
  
  int size=v.size(); 

  if(size==0)
 {
    
    return 0;
 }

  if(size==1 )
  {
    return v[0];
  }


  if(v[0]!=v[1]) return v[0];

  if(v[size-1]!=v[size-2]) return v[size-1];

  int lower=1,higher=size-2;
  
  while(lower<=higher)
  {
    int middle=lower+(higher-lower)/2;

    //checking whether the element at the middle index is single or not .
    //agar woh single hoga na uski bgl wale se pategi na use dusre bgl wale sse....

    if(v[middle]!=v[middle-1] and v[middle]!=v[middle+1])
    {
        return v[middle];
    }

    /*
    now checking the conditon ...
    agar single wala admi agar hai toh aisa pair banega....
    (even,odd) ---agar aisa index ban rha hai is hisaab admi jo single hai woh right main hoga...
    (odd,even) ---agae aisa index ban rha hai is hissab se admi single hai woh left main hoga...
    */

   //the sinngle element to be present in the right half..
   if((middle%2==1 and v[middle]==v[middle-1])or(middle%2==0 and v[middle]==v[middle+1]))
   {
    lower=middle+1;
   }

   //the single element to be present in the left half is ,the condition is to be ;
   if((middle%2==1 and v[middle]==v[middle+1])or(middle%2==0 and v[middle]==v[middle-1]))
   {
    higher=middle-1;
   }
  }
}

int main()
{
    vector<int> v;
    int size;
    cout<<"\nenter the size of the elements in the vector"<<endl;
    cin>>size;
    cout<<"\n enter the elements in the vector "<<endl;
    for(int i=0;i<size;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

    // int target;
    // cout<<"\nenter the value of target"<<endl;
    // cin>>target;

    
    int single_pana= single(v);
    if(single_pana==0)
    cout<<"\n no element is present .Please enter the elements properly.Jode dung se daalo"<<endl;
    else
    cout<<"\n the only single element present in the mingle group is "<<single_pana<<endl;
}