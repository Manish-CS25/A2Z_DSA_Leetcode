class Solution {

public:
    void helper(vector<string>& p, int cc, int oc, int n, string s) {
        if (oc == n && cc == n) {
            p.push_back(s);
            return;
        }

        if (oc < n) {
            helper(p, cc, oc + 1, n, s + "(");
        }

        if (oc > cc) {
            helper(p, cc + 1, oc, n, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> p;
        int cc = 0, oc = 0;

        helper(p, cc, oc, n, "");

        return p;
    }
};