class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++){
            for(int j = find(nums2.begin(), nums2.end(), nums1[i])-nums2.begin()+1; j < nums2.size(); j++){
                if(nums1[i] < nums2[j]){
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};