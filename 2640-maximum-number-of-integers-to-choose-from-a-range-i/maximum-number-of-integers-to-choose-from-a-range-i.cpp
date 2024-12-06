
class Solution {
public:
    bool bs(vector<int>& banned, int k) {
        int l = 0;
        int r = banned.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (banned[mid] == k)
                return true;
            else if (banned[mid] < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {

        int cnt = 0;
        int sum = 0;
        sort(banned.begin(), banned.end());
        for (int i = 1; i <= n; i++) {
            if (!bs(banned, i)) {
                if (sum + i <= maxSum) {
                    sum += i;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};