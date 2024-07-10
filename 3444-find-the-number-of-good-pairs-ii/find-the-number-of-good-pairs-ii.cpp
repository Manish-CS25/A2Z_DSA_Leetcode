class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;

        // Map to store the multiples of k in nums2
        for (auto n : nums2) {
            mp[n * k]++;
        }
        
        for (auto n : nums1) {
            for (int i = 1; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    ans += mp[i];
                    // To Handle the Left-over elements after sqrt(n)
                    // like in 24 -> 6,8,12,24
                    if (i != n / i) {
                        ans += mp[n / i];
                    }
                }
            }
        }

        return ans;
    }
};