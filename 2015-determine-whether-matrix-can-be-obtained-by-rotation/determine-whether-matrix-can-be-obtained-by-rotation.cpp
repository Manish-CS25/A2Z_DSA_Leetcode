class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int r = 4; // No. of rotation , counting first one also
        int n = mat.size();
        while (r--) {
            if (mat == target)
                return true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            // revrese the rows
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};