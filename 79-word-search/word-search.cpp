class Solution {
public:
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis,
             int n, int m, string &word, int k) {
        if (k == word.size())
            return true;
        vis[i][j] = 1;

        for (int t = 0; t < 4; t++) {
            int nr = i + r[t];
            int nc = j + c[t];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 &&
                board[nr][nc] == word[k]) {
                // cout << word[k];
                if(dfs(nr, nc, board, vis, n, m, word, k+1))
                return true;
            }
        }

        vis[i][j]=0;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, vis, n, m, word, 1))
                        return true;
                }
            }
        }

        return false;
    }
};