class Solution {
public:
    void f(int ind, string digits, string& comb, vector<string>& ans,
           string s[]) {
        if (ind == digits.size()) {
            ans.push_back(comb);
            return;
        }

        int index = digits[ind] - '0';
       

        for (int i = 0; i < s[index].size(); i++) {
            comb += s[index][i];
            f(ind + 1, digits, comb, ans, s);
            comb.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.size())
            return {};
        string s[10] = {"",
                        "",
                        "abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz"};

        vector<string> ans;
        string comb = "";

        f(0, digits, comb, ans, s);

        return ans;
    }
};