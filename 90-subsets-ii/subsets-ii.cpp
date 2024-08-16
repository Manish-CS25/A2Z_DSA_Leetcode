class Solution {
public:
    void f(int i, vector<int>& sub, set<vector<int>> &ans, vector<int>& nums) {
        if (i == nums.size()) {
            ans.insert(sub);
            return;
        }

        sub.push_back(nums[i]);
        f(i + 1, sub, ans, nums);
        sub.pop_back();
        f(i + 1, sub, ans, nums);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> sub;
        vector<vector<int>> res;

        f(0, sub, ans, nums);

        for (auto it : ans)
            res.push_back(it);
        return res;
    }
};