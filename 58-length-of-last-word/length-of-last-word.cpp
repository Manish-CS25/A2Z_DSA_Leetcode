class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                l++;
                ans = l;
            }
            // l++;
            else {
                l = 0;
            }
        }
        return ans;
    }
};