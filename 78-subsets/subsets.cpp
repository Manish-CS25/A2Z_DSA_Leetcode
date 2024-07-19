// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> powerset;
//         int n = nums.size();

//         int size = (1 << n) - 1;
//         for (int i = 0; i <= size; i++) {
//             vector<int> sub = {};
//             for (int j = 0; j < n; j++) {
//                 if (i & (1 << j))
//                     sub.push_back(nums[j]);
//             }
//             powerset.push_back(sub);
//         }
//         return powerset;
//     }
// };

// ====================Optimal Solution using backtracking=======

class Solution {
public:
    void setMaker(int index, vector<int>& nums, vector<vector<int>>& powerset,
                  vector<int> subset, int n) {
        if (index == n) {
            powerset.push_back(subset);
            return;
        }

        // take element
        subset.push_back(nums[index]);
        setMaker(index + 1, nums, powerset, subset, n);

        // not take element
        subset.pop_back();
        setMaker(index + 1, nums, powerset, subset, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> powerset;

        setMaker(0, nums, powerset, {}, n);

        return powerset;
    }
};