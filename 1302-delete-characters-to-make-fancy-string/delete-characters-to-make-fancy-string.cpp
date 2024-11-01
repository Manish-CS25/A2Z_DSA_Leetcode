class Solution {
public:
    string makeFancyString(string s) {
        int f = 1;
        char ch = s[0];
        string result = "";
        result+=ch;
        int n = s.size();

        if (n <= 2)
            return s;

        for (int i = 1; i < n; i++) {
            if (s[i] == ch)
                f++;

            else {

                ch = s[i];
                f = 1;
            }

            if (f < 3)
                result += s[i];
        }

        return result;
    }
};