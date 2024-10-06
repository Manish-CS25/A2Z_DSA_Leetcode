class Solution {
public:
    int maxProduct(vector<int>& nums) {

        long long ans = INT_MIN;
        int n = nums.size();


        sort(nums.begin() , nums.end());
        
        // for (int i = 0; i < n; i++) {

        //     for (int j = i + 1; j < n; j++) {
        //         long long m = (nums[j] - 1) * (nums[i] - 1);
        //         ans = max(ans, m);
        //     }
        // }

        long long m = (nums[n-1] - 1) * (nums[n-2] - 1);

        return m;
        // return ans;
    }
};