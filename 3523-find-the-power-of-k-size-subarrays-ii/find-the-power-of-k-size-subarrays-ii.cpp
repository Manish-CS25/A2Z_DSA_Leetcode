class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        if (k > n)
            return ans;

        if (k == 1)
            return nums;

        // Check the first subarray of size k
        bool flag = true;
        for (int i = 0; i < k - 1; i++) {
            if (nums[i] + 1 != nums[i + 1]) {

                flag = false;
                break;
            }
        }

        if (flag) {
            ans[0] = nums[k - 1];
        }

        // Sliding window for the remaining subarrays
        for (int i = 1; i <= n - k; ++i) {
            if (nums[i + k - 1] != nums[i + k - 2] + 1) {
                flag = false;
            } else if (!flag) {
                // If the previous subarray was not consecutive, check this one
                // from scratch
                flag = true;
                for (int j = i; j < i + k - 1; ++j) {
                    if (nums[j + 1] != nums[j] + 1) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                ans[i] = nums[i + k - 1];
            }
        }
        return ans;
    }
};