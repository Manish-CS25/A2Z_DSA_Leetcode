class Solution {
public:
    int minSteps(int n) {
        // vector<int> dp(n + 1, 0);

        // for (int i = 2; i <= n; i++) {
        //     int ans2, ans3, ans4, ans5;
        //     if (i < 6)
        //         dp[i] = n;
        //     if (i % 2 == 0)
        //         dp[i] = dp[i / 2] + 2;
        //     else if (i % 3 == 0)
        //         dp[i] = dp[i / 3] + 3;
        //     else if (i % 4 == 0)
        //         dp[i] = dp[i / 4] + 4;
        //     else if (i % 5 == 0)
        //         dp[i] = dp[i / 5] + 5;
        //     else
        //         dp[i] = i;
        // }

        // return dp[n];

        int steps = 0;
        int curr_len = 1;
        int copied_len = 0;
        bool copied = false;
        while (curr_len < n) {
            if (!copied) {
                copied = true;
                copied_len = curr_len;

            } else {
                curr_len += copied_len;
                if (n % (curr_len) == 0) {
                    copied = false;
                }
            }
            steps += 1;
        }
        return steps;
    }
};