class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0, j = 0;
        int n = s.size();
        int m = spaces.size();
        while (i < n) {

            if (j < m && i == spaces[j]) {
                ans += " ";
                j++;

            }

            else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};