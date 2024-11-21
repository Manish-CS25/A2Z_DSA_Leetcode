class Solution {
public:
    int r[4] = {0, 1, 0, -1};
    int c[4] = {1, 0, -1, 0};

    void markGuarded(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int nr = i + r[k];
            int nc = j + c[k];

            while (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                if (grid[nr][nc] == 1 || grid[nr][nc] == 2)
                    break;
                if (grid[nr][nc] == 0)
                    grid[nr][nc] = -1;
                nr += r[k];
                nc += c[k];
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 2;
        }

        int cnt = 0;
        for (auto &g : guards) {

            markGuarded(g[0], g[1], grid);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};