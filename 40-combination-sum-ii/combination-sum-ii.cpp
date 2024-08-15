class Solution {
    void comb(int index, vector<int>& candidates, int target,
              vector<vector<int>>& ans, vector<int>& subseq, int n) {

        if (target == 0) {
            ans.push_back(subseq);
            return;
        }

        for (int i = index; i < n; i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            subseq.push_back(candidates[i]);

            comb(i + 1, candidates, target - candidates[i], ans, subseq, n);

            subseq.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subseq;
        int n = candidates.size();
        comb(0, candidates, target, ans, subseq, n);
        return ans;
    }
};