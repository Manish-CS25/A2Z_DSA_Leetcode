class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        // int min_index;

        vector<int> lucky;
        vector<int> row_index(n);

        for (int i = 0; i < n; i++) {

            int min = INT_MAX;
            int min_index = -1;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    min_index = j;
                }
            }

            row_index[i] = min_index;
        }

        for (int i = 0; i < n; i++) {
            int row = row_index[i];

            int max = INT_MIN;
            for (int j = 0; j < n; j++) {
                if (matrix[j][row] > max)
                    max = matrix[j][row];
            }
            
            if (max == matrix[i][row])
                lucky.push_back(max);
        }
        return lucky;
    }
};