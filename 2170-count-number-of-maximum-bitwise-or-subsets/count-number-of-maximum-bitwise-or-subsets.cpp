class Solution {
public:
    void helper(int i, vector<int>& nums, int& ans, int& cnt, long long maxi) {
        if (i == nums.size()) {

            if (ans == maxi)
                cnt++;
            cout << ans << endl;
            return;
        }

        int t = ans;
        ans = ans | nums[i];

        helper(i + 1, nums, ans, cnt, maxi);

        helper(i + 1, nums, t, cnt, maxi);
    }

    int countMaxOrSubsets(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();
        long long max_or = 0;
        for (auto it : nums) {
            max_or = max_or | it;
        }

        int cnt = 0;
        helper(0, nums, ans, cnt, max_or);

        return cnt;
    }
};