class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        int temp = 1e9;
        int j = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for(int j=0 ;j<nums2.size();j++){

                if (nums1[i] == nums2[j]) {
                    ans.push_back(nums2[j]);
                    nums1[i]=INT_MIN;
                    nums2[j]=INT_MAX;
                    break;
                }

                
            }
        }
        return ans;
    }
};