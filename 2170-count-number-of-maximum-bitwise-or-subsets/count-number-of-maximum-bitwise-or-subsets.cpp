// class Solution {
// public:
//     void helper(int i, vector<int>& nums, int& ans, int& cnt, long long maxi)
//     {
//         if (i == nums.size()) {

//             if (ans == maxi)
//                 cnt++;
//             cout << ans << endl;
//             return;
//         }

//         int t = ans;
//         ans = ans | nums[i];

//         helper(i + 1, nums, ans, cnt, maxi);

//         helper(i + 1, nums, t, cnt, maxi);
//     }

//     int countMaxOrSubsets(vector<int>& nums) {

//         int ans = 0;
//         int n = nums.size();
//         long long max_or = 0;
//         for (auto it : nums) {
//             max_or = max_or | it;
//         }

//         int cnt = 0;
//         helper(0, nums, ans, cnt, max_or);

//         return cnt;
//     }
// };

//====================DP solution ============================

class Solution {
public:
    int helper(int i, vector<int>& nums, int ans, vector<vector<int>>& dp,
               long long maxi) {
        if (i == nums.size()) {

            if (ans == maxi) {
                return 1;
            }
            return 0;
        }

        if (dp[i][ans] != -1) {
            return dp[i][ans];
        }

        int include = helper(i + 1, nums, ans | nums[i], dp, maxi);

        int exclude = helper(i + 1, nums, ans, dp, maxi);

        dp[i][ans] = include + exclude;
        return dp[i][ans];
    }

    int countMaxOrSubsets(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();
        long long max_or = 0;
        for (auto it : nums) {
            max_or = max_or | it;
        }

        // Create a 2D dp table, where dp[i][ans] is initialized to -1
        vector<vector<int>> dp(n, vector<int>(max_or + 1, -1));

        return helper(0, nums, ans, dp, max_or);
    }
};