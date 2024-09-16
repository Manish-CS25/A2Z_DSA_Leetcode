class Solution {
public:
    int longestValidParentheses(string s) {
        int op = 0;
        int cp = 0;
        int maxi = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                op++;
            else
                cp++;
            if (cp > op)
                op = cp = 0;
            else if (op == cp) {
                maxi = max(maxi, op * 2);
            }
        }

        op = cp = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(')
                op++;
            else
                cp++;
            if (cp < op)
                op = cp = 0;
            else if (op == cp) {
                maxi = max(maxi, cp * 2);
            }
        }
        return maxi;
    }
};