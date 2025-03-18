class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size(), val = 0;
        for (int l = 0, r = 0; r < n; r++) {
            while (l < r && ((val & nums[r]) != 0)) {
                val ^= nums[l];
                l++;
            }
            val |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};