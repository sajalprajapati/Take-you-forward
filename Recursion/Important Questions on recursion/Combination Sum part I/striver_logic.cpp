void pickingAndNotPicking(int index,vector<vector<int>> &answer,vector<int> ds,vector<int> &originalArray,int target)
{
   //base case condition...
   if(index==originalArray.size())
   {
     if(target==0)
     {
        answer.push_back(ds);
     }
    
     return;
   }


    if(originalArray[index]<=target)
    {
     ds.push_back(originalArray[index]);
     pickingAndNotPicking(index,answer,ds,originalArray,target-originalArray[index]);
     ds.pop_back();
    }

    pickingAndNotPicking(index+1,answer,ds,originalArray,target);
}



vector<vector<int>> combinationSum(vector<int> &originalArray,int target)
{
    vector<vector<int>> answer;
    vector<int> data_structure;
    pickingAndNotPicking(0,answer,data_structure,originalArray,target);
    return answer;
}