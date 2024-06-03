class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int n = s.size();
        int hash[256] = {0};
        int L = 0;
        int R = 0;
        int maxlen = 0;
        while (R < n) {
            if (hash[s[R]] > 0)
                L = max(L, hash[s[R]]);
            hash[s[R]] = R + 1;
            maxlen = max(maxlen, R - L + 1);
            R++;
        }
        return maxlen;
    }
};