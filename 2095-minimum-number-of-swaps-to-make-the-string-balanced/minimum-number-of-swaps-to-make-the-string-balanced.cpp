class Solution {
public:
    int minSwaps(string s) {

        int inbalance_cnt = 0;

        int cb = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[')
                cb--;
            else
                cb++;
            inbalance_cnt = max(cb, inbalance_cnt);
        }
        return (inbalance_cnt + 1) / 2;
    }
};