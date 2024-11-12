class Solution {
public:
    int BS(vector<vector<int>>& items, int q, vector<int>& Beauty) {
        int l = 0;
        int r = items.size() - 1;

        int val = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (q >= items[mid][0]) {
                val = Beauty[mid];
                l = mid + 1;
            } else
                r = mid - 1;
        }

        return val;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {

        int m = items.size();
        vector<int> ans, mxBeauty(m);

        sort(items.begin(), items.end());
        mxBeauty[0] = items[0][1];
        for (int i = 1; i < m; i++) {
            mxBeauty[i] = max(mxBeauty[i - 1], items[i][1]);
        }

        for (auto& q : queries) {
            ans.push_back(BS(items, q, mxBeauty));
        }
        return ans;
    }
};