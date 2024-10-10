// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {

//         int n = nums.size();
//         int maxi = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {

//                 if (nums[j] >= nums[i])
//                     maxi = max(maxi, j - i);
//             }
//         }

//         return maxi > 0 ? maxi : 0;
//     }
// };

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;

        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }

        return maxi;
    }
};
