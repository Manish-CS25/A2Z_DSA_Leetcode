// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (auto it : nums) {
//             mp[it]++;
//         }

//         vector<int> ans;
//         for (auto it : mp) {
//             if (it.second > 1) {
//                 ans.push_back(it.first);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int i = 0, d = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};