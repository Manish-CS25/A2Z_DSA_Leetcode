class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int left_max = values[0];
        int n = values.size();
        for (int i = 1; i < n; i++) {
            if (left_max + values[i] - i > ans)
                ans = left_max + values[i] - i;

            left_max = max(left_max, values[i] + i);
        }
        return ans;
    }
};