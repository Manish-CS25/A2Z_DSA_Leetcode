class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return true;
        if (n == 2) {
            return (!(nums[0] % 2 == nums[1] % 2));
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2)
                return false;
        }

        return true;
    }
};