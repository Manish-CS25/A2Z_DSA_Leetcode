class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr((n * n) + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[grid[i][j]]++;
                if (arr[grid[i][j]] == 2)
                    ans.push_back(grid[i][j]);
            }
        }

        for (int i = 1; i <= n * n; i++) {
            if (arr[i] == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};