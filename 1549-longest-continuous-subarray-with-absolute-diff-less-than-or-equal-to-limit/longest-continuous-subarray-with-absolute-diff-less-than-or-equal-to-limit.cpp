class Solution {
public:
    // Approach

    // Initialization:
    //     Create two pointers, l and r, both starting at the beginning of the
    //     array. Initialize two deques, mindq and maxdq, to keep track of the
    //     minimum and maximum values in the current window. Initialize a
    //     variable maxsize to store the maximum length of the valid subarray
    //     found.

    // Sliding Window:
    //     Use a while loop to iterate with the right pointer r until it reaches
    //     the end of the array.

    // Update Deques:
    //     Max Deque: Remove elements from the back of maxdq that are smaller
    //     than the current element nums[r] (to maintain decreasing order). Min
    //     Deque: Remove elements from the back of mindq that are greater than
    //     the current element nums[r] (to maintain increasing order). Add the
    //     current element nums[r] to both deques.

    // Check Validity:
    //     If the difference between the front elements of maxdq and mindq
    //     exceeds the limit, it means the current window is invalid:
    //         Increment the left pointer l.
    //         Remove the front element from mindq if it is equal to nums[l]
    //         (since we are shrinking the window from the left). Remove the
    //         front element from maxdq if it is equal to nums[l].

    // Update Maximum Size:
    //     Calculate the size of the current valid window (r - l + 1) and update
    //     maxsize if it is larger than the previously recorded maximum size.

    // Move Right Pointer:
    //     Increment the right pointer r to expand the window to the right.

    // Return Result:
    //     After exiting the loop, maxsize will contain the length of the
    //     longest subarray that satisfies the condition.

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        deque<int> mindq, maxdq;

        int maxsize = 1;

        while (r < n) {
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