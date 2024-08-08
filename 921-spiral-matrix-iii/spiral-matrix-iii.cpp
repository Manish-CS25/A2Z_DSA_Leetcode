class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstart,
                                        int cstart) {
        vector<vector<int>> ans;
        // Add the starting point
        ans.push_back({rstart, cstart});

        int n = rows * cols;        // Total number of cells to visit
        int steps = 1;              // Number of steps to move in each direction
        int r = rstart, c = cstart; // Current position

        while (n > 1) { // We already added one cell at the start
            // Move right
            for (int i = 0; i < steps; ++i) {
                c++;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                    --n;
                }
            }
            // Move down
            for (int i = 0; i < steps; ++i) {
                r++;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                    --n;
                }
            }
            // Increase step size for the next two directions
            steps++;

            // Move left
            for (int i = 0; i < steps; ++i) {
                c--;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                    --n;
                }
            }
            // Move up
            for (int i = 0; i < steps; ++i) {
                r--;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                    --n;
                }
            }

            // Increase step size for the next two directions
            steps++;
        }

        return ans;
    }
};