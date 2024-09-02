class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int ans = 0;
        for (auto it : chalk) {
            sum += it;
        }
        long long max_sum = 0;

        while (max_sum + sum <= k) {

            max_sum += sum;
        }
        cout << max_sum;
        for (int i = 0; i < chalk.size(); i++) {
            // cout << i;
            max_sum += chalk[i];

            if (max_sum > k) {
                ans = i;
                cout << i;
                break;
            }
        }
        return ans;
    }
};