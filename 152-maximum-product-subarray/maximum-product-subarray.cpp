class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = INT_MIN;
        int n = nums.size();
        long long pro = 1;

        for (int i = 0; i < n; i++) {
            pro = pro * nums[i];
            maxi = max(maxi, pro);
            if (pro == 0)
                pro = 1;
        }

        //// Second pass to check backward
         pro = 1;
        for (int i = n - 1; i >= 0; i--) {
            pro = pro * nums[i];
            maxi = max(maxi, pro);
            if (pro == 0)
                pro = 1;
        }

        return maxi;
    }
};