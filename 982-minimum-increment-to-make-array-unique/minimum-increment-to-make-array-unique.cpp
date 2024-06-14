class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mov = 0;

        for (int i = 1; i < n; i++) {

            // we will check if previous element is
            // greater than or equal to current element then
            // no. of mov will be diff b/w them +1 and we
            //  we will update current element with previous
            // element +1
            if (nums[i - 1] >= nums[i]) {
                mov += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return mov;
    }
};