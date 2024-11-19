class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        long long ans = 0;
        long long currWinSum = 0;

        int l = 0; // Left pointer of the window
        int r = 0; // Right pointer of the window

        while (r < n) {
            while (st.count(nums[r])) {
                currWinSum -= nums[l];
                st.erase(nums[l]);
                l++;
            }

            currWinSum += nums[r];
            st.insert(nums[r]);

            // If the window size is exactly k
            if (r - l + 1 == k) {

                ans = max(ans, currWinSum);
                currWinSum -= nums[l];
                st.erase(nums[l]);
                l++;
            }

            r++;
        }

        return ans;
    }
};