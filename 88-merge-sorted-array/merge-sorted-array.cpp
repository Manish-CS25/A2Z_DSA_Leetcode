class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0;
        int j = 0;
        // int k =0;
        vector<int> ans;

        while (i < m && j < n) {

            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i++]);
            }

            else {
                ans.push_back(nums2[j++]);
            }
        }
        // when n=0 then nums1 values only
        while (i < m) {
            ans.push_back(nums1[i++]);
        }
        // when m=0 then nums2 values only
        while (j < n) {
            ans.push_back(nums2[j++]);
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
    }
};