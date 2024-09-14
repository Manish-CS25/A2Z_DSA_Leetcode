class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0, maxi_cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                
                maxi_cnt = max(maxi_cnt, ++cnt);
            } else {
                cnt = 0;
            }
        }

        return maxi_cnt;
    }
};
