class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (p.size() == 1)
            return 0;
        vector<int> ans(n, 0);

        priority_queue<int> pq;
        pq.push(p[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            ans[i] = pq.top() - p[i];
            pq.push(p[i]);
        }

        int res = *max_element(ans.begin(), ans.end());

        return res > 0 ? res : 0;
    }
};