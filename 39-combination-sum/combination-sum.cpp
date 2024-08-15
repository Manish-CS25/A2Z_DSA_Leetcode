class Solution {
    void comb(int index, int target, vector<int>& candidates,
              vector<vector<int>>& ans, vector<int>& subseq, int n) {
        if (index == n) {
            if (target == 0)
                ans.push_back(subseq);
            return;
        }

        if (candidates[index] <= target) {
            subseq.push_back(candidates[index]);

            comb(index, target - candidates[index], candidates, ans, subseq, n);
            subseq.pop_back();
        }

        comb(index + 1, target, candidates, ans, subseq, n);

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subseq;
        int n = candidates.size();
        comb(0, target, candidates, ans, subseq, n);
        return ans;
    }
};