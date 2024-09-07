class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // long long maxi = INT_MIN;
        // int n = nums.size();
        // long long pro = 1;

        // for (int i = 0; i < n; i++) {
        //     pro = pro * nums[i];
        //     maxi = max(maxi, pro);
        //     if (pro == 0)
        //         pro = 1;
        // }

        // //// Second pass to check backward
        //  pro = 1;
        // for (int i = n - 1; i >= 0; i--) {
        //     pro = pro * nums[i];
        //     maxi = max(maxi, pro);
        //     if (pro == 0)
        //         pro = 1;
        // }

        // return maxi;

        // in one pass

        int prefix = 1, suffix = 1;
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }
};