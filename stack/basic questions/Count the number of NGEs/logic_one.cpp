class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &indices){
        //write your code here
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int curr = arr[indices[i]];
            stack<int> st;
            int r = n - 1;
            while (r > indices[i]) {
                if (arr[r] > curr) {
                    st.push(arr[r]);
                }
                r--;
            }
            ans[i] = st.size();
        }
        return ans;
       
    }

};