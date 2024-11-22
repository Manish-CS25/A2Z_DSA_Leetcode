class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for (auto& row : matrix) {
            int first = row[0];
            string curr;

            for (auto ele : row) {
                if (ele == first)
                    curr.push_back('0');
                else
                    curr.push_back('1');
            }

            mp[curr]++;
        }

        int maxCnt = 0;

        for (auto it : mp) {
            maxCnt = max(maxCnt, it.second);
        }

        return maxCnt;
    }
};