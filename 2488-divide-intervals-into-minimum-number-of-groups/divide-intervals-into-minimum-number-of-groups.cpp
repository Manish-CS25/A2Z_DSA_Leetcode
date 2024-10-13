class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals based on the start
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            // if next interval is not overlapping to top interval then put it
            // to min heap
            if (!pq.empty() && start > pq.top()) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};