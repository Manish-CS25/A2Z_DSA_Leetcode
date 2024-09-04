class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        int index = -1;
        for (int i = 0; i < m - n + 1; i++) {
            string s = "";
            for (int j = i; j < m; j++) {
                s += haystack[j];
                if (needle == s) {
                    return i;
                }
            }
        }

        return index;
    }
};