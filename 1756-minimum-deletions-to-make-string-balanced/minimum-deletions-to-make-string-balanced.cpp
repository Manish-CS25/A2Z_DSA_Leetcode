class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int ans = 0;
        if (n == 1)
            return 0;
        int cnt = 0;
        int cnt_b = 0;
        // int cnt_a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b')
                cnt_b++;
            if (s[i] == 'a') {
                if (cnt_b) {
                    ans++;
                    cnt_b--;
                }
            }
        }
        return ans;
    }
};