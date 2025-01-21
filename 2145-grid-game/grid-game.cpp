class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int m = grid[0].size();
        long long topSum = 0;
        long long bottomSum = 0;
        long long ans = LONG_MAX;

        for (int i = 0; i < m; i++) {

            topSum += grid[0][i];
        }

        for (int i = 0; i < m; i++) {

            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return ans;
    }
};