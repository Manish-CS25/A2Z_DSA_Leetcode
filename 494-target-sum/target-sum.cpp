class Solution {
public:
    int res = 0;
    int target;
    int sum = 0;
    void dfs(vector<int>& nums, int pos = 0) {
        if (pos == nums.size()) {
            if (sum == target) res++;
            return;
        }
        // trying with minus first
        sum -= nums[pos];
        dfs(nums, pos + 1);
        // backtracking and trying with plus
        sum += nums[pos] * 2;
        dfs(nums, pos + 1);
        // backtracking - resetting sum to the initial value
        sum -= nums[pos];
    }
    int findTargetSumWays(vector<int>& nums, int s) {
        target = s;
        dfs(nums);
        return res;
    }
};