class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod = 1e9 + 7;
        vector<int> subArr;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                // cout<<sum;
                subArr.push_back(sum);
            }
        }

        sort(subArr.begin(), subArr.end());
        long long ans = 0;
        for (int i = left; i <= right; i++) {
            // cout<<subArr[i];
            ans += (subArr[i - 1])%mod;
        }


        return ans % mod;
    }
};