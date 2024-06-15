class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> cp(n);

        for (int i = 0; i < n; i++) {
            cp[i] = {capital[i], profits[i]};
        }

        sort(cp.begin(), cp.end());
        int i = 0;
        priority_queue<int> maxp;

        while (k--) {
            while (i < n && cp[i].first <= w) {
                maxp.push(cp[i].second);
                i++;
            }
            if (maxp.empty())
                break;
            w += maxp.top();
            maxp.pop();
        }

        return w;
    }
};