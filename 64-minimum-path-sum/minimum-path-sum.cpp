class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the start point
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Skip the starting point since it's already initialized
                if (i == 0 && j == 0) {
                    continue;
                }

                else {
                    int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = min(up, left) + +grid[i][j];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};