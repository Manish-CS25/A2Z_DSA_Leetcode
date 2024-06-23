class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        deque<int> mindq, maxdq;

        int maxsize = 1;

        while (r<n) {
            while (!maxdq.empty() && nums[r] > maxdq.back()) {
                maxdq.pop_back();
            }

            while (!mindq.empty() && nums[r] < mindq.back()) {
                mindq.pop_back();
            }

            maxdq.push_back(nums[r]);
            mindq.push_back(nums[r]);

            if (maxdq.front() - mindq.front() > limit) {
                if (mindq.front() == nums[l])
                    mindq.pop_front();
                if (maxdq.front() == nums[l])
                    maxdq.pop_front();
                l++;
            }
            maxsize = max(maxsize, r - l + 1);
            r++;
        }
        return maxsize;
    }
};