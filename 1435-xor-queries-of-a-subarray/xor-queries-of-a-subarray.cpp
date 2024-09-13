class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto it : queries) {
            int l = it[0];
            int r = it[1];
            if (l == r) {
                ans.push_back(arr[l]);
                continue;
            }
            int xr = 0;
            while (l <= r) {
                xr ^= arr[l];
                l++;
            }
            ans.push_back(xr);
        }
        return ans;
    }
};