class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int, pair<int, int>> ps;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> freqR(n, 0), freqC(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int row = ps[arr[i]].first;
            int col = ps[arr[i]].second;
            freqR[row]++;
            freqC[col]++;
            if (freqR[row] == m || freqC[col] == n)
                return i;
        }

        return 0;
    }
};