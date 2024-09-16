class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();
        vector<int> d(n, 0);
        for (int i = 0; i < n; i++) {
            string h = timePoints[i].substr(0, 2);
            int hr = stoi(h);
            string m = timePoints[i].substr(3, 2);
            int min = stoi(m);

            d[i] = 60 * hr + min;
        }

        sort(d.begin(), d.end());
        // Calculate the minimum difference between consecutive time points
        int minDiff = 1440; // Initialize with max possible value (24 hours =
                            // 1440 minutes)
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, d[i] - d[i - 1]);
        }

        // Check the circular difference between the first and last time points
        minDiff = min(minDiff, 1440 + d[0] - d[n - 1]);

        return minDiff;
    }
};