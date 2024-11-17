class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {

        int l = -1, r = 0;
        int n = nums.size();
        int ans = INT_MAX;

        vector<int> pre(n);
        int sum = 0;
        int i = 0;
        for (auto it : nums) {
            sum += it;
            pre[i++] = sum;
        }

        while (r < n) {
            if (l < 0)
                sum = pre[r];
            else
                sum = pre[r] - pre[l];
            if (sum >= k) {
                ans = min(ans, r - l);
                l++;
            } else
                r++;
        }

        if (ans > n)
            return 0;
        return ans;
    }
};