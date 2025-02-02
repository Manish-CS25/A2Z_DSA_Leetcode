class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return true;

        if (nums[0] >= nums[n - 1]) {
            int end;
            for (int i = 0; i < n - 1; i++) {
                if (nums[i + 1] < nums[i]) {
                    end = i;
                    break;
                }
            }

            for (int i = end + 1; i < n - 1; i++) {
                if (nums[i] > nums[i + 1])
                    return false;
            }

        }

        else {
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] > nums[i + 1])
                    return false;
            }
        }

        return true;
    }
};