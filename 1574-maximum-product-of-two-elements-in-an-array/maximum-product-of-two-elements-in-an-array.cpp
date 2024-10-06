class Solution {
public:
    int maxProduct(vector<int>& nums) {

        long long ans = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {
                long long m = (nums[j] - 1) * (nums[i] - 1);
                ans = max(ans, m);
            }
        }
        return ans;
    }
};