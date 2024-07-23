class Solution {
public:
    int sol(vector<int>& arr) {

        int n = arr.size();
        if (n == 1)
            return arr[0];
        if (n == 2)
            return max(arr[0], arr[1]);

        vector<int> dp(n + 1, -1);

        dp[1] = arr[0];
        dp[2] = max(arr[0], arr[1]);

        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
        }

        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> with_1st, with_last;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                with_last.push_back(nums[i]);
            if (i != n - 1)
                with_1st.push_back(nums[i]);
        }
        return max(sol(with_1st), sol(with_last));
    }
};