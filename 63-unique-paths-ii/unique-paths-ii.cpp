#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the start or end is an obstacle, there is no path.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the start point
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Skip the starting point since it's already initialized
                if (i == 0 && j == 0) {
                    continue;
                }

                // If there's an obstacle at the current cell, the number of
                // paths to it is 0
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
