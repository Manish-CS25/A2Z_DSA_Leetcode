class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            int ns = intervals[i][0];
            int ne = intervals[i][1];
            if (ns > end) {
                ans.push_back({start, end});
                start = ns;
                end = ne;
            }

            else {
                if (ne > end) {
                    end = ne;
                }
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};