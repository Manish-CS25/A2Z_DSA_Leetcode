class Solution {
public:
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};

    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, 
             const string& word, int k, int n, int m) {
        if (k == word.size())  // Base case: matched the whole word
            return true;
        
        vis[i][j] = 1;  // Mark current cell as visited

        // Explore all 4 directions (up, right, down, left)
        for (int t = 0; t < 4; t++) {
            int nr = i + r[t];
            int nc = j + c[t];

            // Check if the new cell is within bounds and matches the current character in word
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && board[nr][nc] == word[k]) {
                if (dfs(nr, nc, board, vis, word, k + 1, n, m))  // Recursive call with next character
                    return true;
            }
        }

        vis[i][j] = 0;  // Backtrack, unmark the current cell before returning
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Try to start DFS from every cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first character matches, start the DFS from there
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, vis, word, 1, n, m))  // Start DFS from the second character
                        return true;
                }
            }
        }

        return false;  // No valid path found
    }
};
