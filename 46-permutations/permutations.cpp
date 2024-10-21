// class Solution {
// public:
//     void permute(int index, vector<int> nums, vector<vector<int>>& ans) {
//         if (index == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }

//         for (int i = index; i < nums.size(); i++) {
//             swap(nums[index], nums[i]);
//             permute(index + 1, nums, ans);
//             swap(nums[index], nums[i]);
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {

//         vector<vector<int>> ans;

//         permute(0, nums, ans);

//         return ans;
//     }
// };

// ================Another Approach===========================

class Solution {
public:
    void permute(vector<int> nums, vector<int>& ds, int fq[],
                 vector<vector<int>>& ans) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (fq[i] == 0) {
                ds.push_back(nums[i]);
                fq[i] = 1;
                permute(nums, ds, fq, ans);

                fq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        int fq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            fq[i] = 0;

        permute(nums, ds, fq, ans);

        return ans;
    }
};