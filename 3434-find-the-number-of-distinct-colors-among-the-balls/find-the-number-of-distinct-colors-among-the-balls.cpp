class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        set<int> sz;
        unordered_map<int, int> mp;
        unordered_map<int, int> freq; // Tracks occurrences of column values

        for (int i = 0; i < n; i++) {
            int index = queries[i][0], col = queries[i][1];

            if (mp.find(index) != mp.end()) {
                int prev_col = mp[index];
                
                // Reduce frequency of prev_col
                freq[prev_col]--;

                // If prev_col is no longer in any key, remove it from sz
                if (freq[prev_col] == 0) {
                    sz.erase(prev_col);
                    freq.erase(prev_col); // Cleanup
                }
            }

            // Insert new column value and track frequency
            sz.insert(col);
            freq[col]++;

            mp[index] = col;

            ans[i] = sz.size();
        }
        return ans;
    }
};
