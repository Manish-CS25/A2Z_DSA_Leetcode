class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                char c = st.top(); st.pop();
                if ((c == '(' and s[i] == ')') or (c == '[' and s[i] == ']') or
                    (c == '{' and s[i] == '}'))
                    continue;
                else return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};