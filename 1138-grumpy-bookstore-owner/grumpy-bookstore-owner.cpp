class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int default_satisfied = 0;

        int max_window_sum = 0;
        int n = customers.size();
        //// count satisfied customers initially when store keeper is not grumpy
        ///mean grumpy[i]==0
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                default_satisfied += customers[i];
        }

        // now find a sub array of minutes(k) in customers for which customer
        // satisfication is greater even if store keeper is grumpy

        for (int i = 0; i < (n - minutes + 1); i++) {
            int window_sum = 0;
            for (int j = 0; j < minutes; j++) {
                if (grumpy[i + j] == 1) {
                    window_sum += customers[i + j];
                }
                max_window_sum = max(max_window_sum, window_sum);
            }
        }

        return default_satisfied + max_window_sum;
    }
};