class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = INT_MAX;

        deque<int> dq;

        vector<long long> cml_sum(n, 0);

        int j = 0;

        while (j < n) {
            if (j == 0)
                cml_sum[j] = nums[j];
            else
                cml_sum[j] = cml_sum[j - 1] + nums[j];
            if (cml_sum[j] >= k) {
                ans = min(ans, j + 1);
            }

            while (!dq.empty() && cml_sum[j] - cml_sum[dq.front()] >= k) {
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && cml_sum[j] <= cml_sum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};