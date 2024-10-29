#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    // Possible movements: up-right, right, down-right
    int row[3] = {-1, 0, 1};
    int col[3] = {1, 1, 1};

    int helper(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& memo) {
        // If already computed, return the stored result
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxMoves = 0; // Initialize maximum moves from the current cell

        // Check all possible moves: down-right, right, and up-right
        for (int k = 0; k < 3; k++) {
            int n_row = i + row[k];
            int n_col = j + col[k];

            // Ensure the new cell is within bounds and has a strictly larger
            // value
            if (n_row >= 0 && n_row < grid.size() && n_col >= 0 &&
                n_col < grid[0].size() && grid[n_row][n_col] > grid[i][j]) {
                // Recursively explore the next cell
                maxMoves = max(maxMoves, 1 + helper(n_row, n_col, grid, memo));
            }
        }

        // Store the result in memoization table
        memo[i][j] = maxMoves;
        return memo[i][j];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        // Create a memoization table initialized to -1
        vector<vector<int>> memo(m, vector<int>(n, -1));

        // Start a path from each cell in the first column
        for (int i = 0; i < m; i++) {
            cnt = max(cnt, helper(i, 0, grid, memo));
        }

        return cnt; // Return the maximum number of moves
    }
};
