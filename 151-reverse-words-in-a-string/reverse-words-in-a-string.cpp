class Solution {
public:
    string reverseWords(string s) {

        string result;
        int n = s.size();
        stack<string> st;

        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            // Extract the word
            result = "";
            while (i < n && s[i] != ' ') {
                result += s[i];
                i++;
            }

            if (!result.empty()) {
                st.push(result);
            }
        }

        s = "";

        while (!st.empty()) {
            s += st.top();
            st.pop();
            if (!st.empty()) {
                s += " "; // Add space between words
            }
        }

        return s;
    }
};