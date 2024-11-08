class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();
        vector<int> ans(n);
        int xr = 0;
        for (auto& it : nums) {
            xr ^= it;
        }
        int Maxor = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {

            ans[i] = xr ^ Maxor;

            xr ^= nums.back();
            nums.pop_back();
        }

        return ans;
    }
};