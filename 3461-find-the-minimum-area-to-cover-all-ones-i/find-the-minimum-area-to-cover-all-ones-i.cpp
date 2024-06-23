class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int L = 1010;
        int R = 0;
        int U = 1010;
        int D = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    L = min(L, j);
                    R = max(R, j);
                    U = min(U, i);
                    D = max(D, i);
                }
            }
        }

        return (R - L + 1) * (D - U + 1);
    }
};