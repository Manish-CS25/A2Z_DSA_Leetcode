class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        char pre = s[0];
        char post = pre;
        string result;

        int i = 0;
        while (i < n) {
            if (post != s[i])
                return false;

            result = "";
            while (i < n && s[i] != ' ') {
                result += s[i];
                i++;
            }

            post = result.back();

            i++;
        }

        if (pre != result.back())
            return false;
        return true;
    }
};