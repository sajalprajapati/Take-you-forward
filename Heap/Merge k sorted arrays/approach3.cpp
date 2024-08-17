void merge(vector<int> &arr,int start,int mid,int end)
    {
        vector<int>temp(end-start+1);
        int left = start,right = mid+1,index =0;
        while(left<=mid && right<=end)
        {
            if(arr[left]<=arr[right])
            {
                temp[index]=arr[left];
                left++;
                index++;
            }
            else
            {
                temp[index] = arr[right];
                index++;
                right++;
            }
        }
        while(left<=mid)
        {
            temp[index]=arr[left];
            index++;
            left++;
        }
        while(right<=end)
        {
            temp[index]=arr[right];
            index++;
            right++;
        }
        
        index = 0;
        while(start<=end)
        {
            arr[start] = temp[index];
            start++;
            index++;
        }
    }
    void mergesort(vector<int>&arr,int start,int end,int portion,int k )
    { 
        if(portion<2)
        return;
        int mid = start + (portion/2)*k-1;
        mergesort(arr, start,mid,portion/2,k);
        mergesort(arr,mid+1,end,portion - portion/2,k);
        merge(arr,start,mid,end);
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<K;j++)
            ans.push_back(arr[i][j]);
        }
        mergesort(ans,0,ans.size()-1,K,K);
        return ans;
    }

