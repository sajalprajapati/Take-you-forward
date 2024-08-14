class Solution {
public:
    int numberOfSubstrings(string s) 
    {
     int lastSeenIndex[3]={-1,-1,-1};
     int n=s.length(),count=0;
     for(int i=0;i<n;i++)
     {
        lastSeenIndex[s[i]-'a']=i;

        if(lastSeenIndex[0]!=-1 and lastSeenIndex[1]!=-1 and lastSeenIndex[2]!=-1)
        {
            int minIndex1=min(lastSeenIndex[0],lastSeenIndex[1]);
            int minIndex2=min(minIndex1,lastSeenIndex[2]);
            count=count+(1+minIndex2);
        }
        
     }  
     return count; 
    }
};