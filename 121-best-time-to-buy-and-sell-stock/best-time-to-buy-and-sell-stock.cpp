class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (p.size() == 1)
            return 0;
        int maxi = INT_MIN;

        priority_queue<int> pq;
        pq.push(p[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            maxi = max(maxi, pq.top() - p[i]);

            pq.push(p[i]);
        }

        return maxi > 0 ? maxi : 0;
    }
};