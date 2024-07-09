class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tw = 0;
        int n = customers.size();
        int st = customers[0][0];
        double w = customers[0][1];
        tw = w;
        st = st + w;
        for (int i = 1; i < n; i++) {
            if (st < customers[i][0]) {
                w = customers[i][1];
                tw += w;
                st = customers[i][1] + customers[i][0];
            } else {
                w = st + customers[i][1] - customers[i][0];
                tw += w;
                st = st + customers[i][1];
            }
        }
        return (tw / n);
    }
};