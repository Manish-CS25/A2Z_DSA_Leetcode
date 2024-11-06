class Solution {
public:
    int setBits(int val) {
        if (val == 0)
            return 0;

        int cnt = 0;
        while (val > 0) {
            if (val % 2 == 1)
                cnt++;
            val = val / 2;
        }

        return cnt;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        vector<int> count(n);
        for (int i = 0; i < n; i++) {
            count[i] = setBits(nums[i]);
        }

        while (k < n) {
            for (int i = 1; i < n; i++) {
                if (count[i] == count[i - 1] && nums[i] < nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            }
            if (check(nums))
                return true;
            k++;
        }

        return false;
    }
};