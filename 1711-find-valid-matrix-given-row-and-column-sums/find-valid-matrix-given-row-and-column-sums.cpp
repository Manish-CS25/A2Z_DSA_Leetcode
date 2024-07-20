class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowsum,
                                      vector<int>& colsum) {

        int n = rowsum.size();
        int m = colsum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        int i = 0;
        int j = 0;
        while (i < n && j < m) {

            int mini = min(rowsum[i], colsum[j]);
            ans[i][j] = mini;
            rowsum[i] -= mini;
            colsum[j] -= mini;

            if (rowsum[i] == 0) {
                i++;
            }
            if (colsum[j] == 0)
                j++;
        }

        return ans;
    }
};