class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int cnt = 0;
        int n = nums.size();

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        for (int i = 0; i < n - 1; i++) {

            if (prefix[i] >= (prefix[n - 1] - prefix[i])) {
                cnt++;
            }
        }

        return cnt;
    }
};