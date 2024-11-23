class Solution {
public:
    void stoneFall(int i, int j, vector<vector<char>>& box) {
        // Move the stone down as long as there's an empty space below.
        while (j + 1 < box[0].size() && box[i][j+1] == '.') {
            box[i][j+1] = '#';  // Move the stone down.
            box[i][j] = '.';  // Empty the current position.
            j++;  // Move down.
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();

        // Simulate the falling of stones.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m-1; j >=0; j--) {
                if (box[i][j] == '#') {
                    stoneFall(i, j, box);
                }
            }
        }

        // Rotate the matrix 90 degrees clockwise.
        vector<vector<char>> ans(m, vector<char>(n, '.'));  // Create a new matrix to store the rotated result.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = box[i][j];  // Rotate the element.
            }
        }

        return ans;  // Return the rotated matrix.
    }
};
