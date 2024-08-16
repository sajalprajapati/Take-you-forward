 int l=0;int r=0;int k=0;
        int n=str1.size();
        int m=str2.size();
        int minlen=INT_MAX;string ans="";
        
        while(r<n&&k<m){
            if(str1[r]==str2[k]){
                k++;
            }
            if(k==m){
                k--;
                l=r;
                while(l>=0&&k>=0){
                    if(str1[l]==str2[k]){
                        k--;
                    }
                    l--;
                }
                k=0;
                l++;
                if(minlen>r-l+1){
                minlen=r-l+1;
                ans=str1.substr(l,r-l+1);
                }
                r=l+1;
            }
            r++;
        }
        return ans;