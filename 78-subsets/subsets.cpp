class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        int n = nums.size();
      
        int size = (1 << n) - 1;
        for (int i = 0; i <= size; i++) {
            vector<int> sub = {};
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    sub.push_back(nums[j]);
            }
            powerset.push_back(sub);
        }
        return powerset;
    }
};