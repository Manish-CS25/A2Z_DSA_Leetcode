class Solution {
public:
    bool dfs(int row, int col, vector <vector < int >> &vis,
             vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n,
             int m) {
        bool f = 1;
        vis[row][col] = 1;
        if(!grid1[row][col]) f=0;
        int nrow[4] = {0, -1, 0, +1};
        int ncol[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int n_row = row + nrow[i];
            int n_col = col + ncol[i];

            if (n_row < n && n_row >= 0 && n_col < m && n_col >= 0 &&
                grid2[n_row][n_col] && !vis[n_row][n_col]) {
                if (!dfs(n_row, n_col, vis, grid1, grid2, n, m))
                    f = 0;
            }
        }
        return f;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;

        vector < vector < int >> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid2[i][j] &&
                    dfs(i, j, vis, grid1, grid2, n, m))
                    ans++;
            }
        }
        return ans;
    }
};