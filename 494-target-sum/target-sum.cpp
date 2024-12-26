class Solution {
public:
    int res = 0;
    int target;
    int sum = 0;
    int limits[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    void dfs(vector<int>& nums, int pos = 0) {
        // checking if we finished using all numbers on this branch
        if (pos == nums.size()) {
            // and in case incrementing res
            if (sum == target) res++;
            return;
        }
        // dropping the DFS when it makes no sense to continue
        if (abs(target - sum) > limits[pos]) return;
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
        for (int i = nums.size() - 1; i >= 0; i--) limits[i] = limits[i + 1] + nums[i];
        target = s;
        dfs(nums);
        return res;
    }
};