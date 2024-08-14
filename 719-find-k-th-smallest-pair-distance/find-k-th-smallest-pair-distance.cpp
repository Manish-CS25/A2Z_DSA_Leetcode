class Solution {
public:
    int smallestCount(vector<int>& nums, int v) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int j = 1;
        while (j < n) {
            while (nums[j] - nums[i] > v) {
                ++i;
            }
            count += j - i;
            j++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {

        // ==========Brute force=============
        // vector<int> a;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {

        //         a.push_back(abs(nums[i] - nums[j]));
        //     }

        //     sort(a.begin(), a.end());

        //     return a[k - 1];

        // =============optimal using Binary Search ========
        sort(nums.begin(), nums.end());
        int low = 0;
        int n = nums.size();
        int high = nums[n - 1] - nums[0];
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = smallestCount(nums, mid);
            if (cnt < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};