// class Solution {
// public:
//     int waysToSplitArray(vector<int>& nums) {

//         int cnt = 0;
//         int n = nums.size();

//         vector<long long> prefix(n, 0);
//         prefix[0] = nums[0];
//         for (int i = 1; i < n; i++) {
//             prefix[i] = nums[i] + prefix[i - 1];
//         }

//         for (int i = 0; i < n - 1; i++) {

//             if (prefix[i] >= (prefix[n - 1] - prefix[i])) {
//                 cnt++;
//             }
//         }

//         return cnt;
//     }
// };



/// More optimal
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Keep track of sum of elements on left and right sides
        long long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};