class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0;
        int r = 1;
        int sum = nums[0];
        int maxSum = nums[0];
        while (r < n) {

            if (nums[r] <= nums[r - 1]) {
                l = r;
                sum = nums[r];
            }

            else
                sum += nums[r];
            r++;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};