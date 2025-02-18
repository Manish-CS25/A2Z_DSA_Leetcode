class Solution {
public:
    string smallestNumber(string p) {
        int n = p.size();
        string ans = "";
        for(int i = 0; i <= n; i++) {
            ans.push_back(i + 1 + '0');
        }
        int j = 0;
        while (j < n) {
            if (p[j] == 'D') {
                int k = j;
                while (j < n && p[j] == 'D') {
                    j++;
                }
                reverse(ans.begin() + k, ans.begin() + j + 1);
            } else {
                j++;
            }
        }
        return ans;
    }
};