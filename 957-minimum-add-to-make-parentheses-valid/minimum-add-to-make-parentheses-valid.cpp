class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.size() == 1)
            return 1;
        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (!st.empty()) {
                char ch = st.top();
                if (ch == '(' && s[i] == ')')
                    st.pop();
                else
                    st.push(s[i]);

            } else
                st.push(s[i]);
        }

        return st.size();
    }
};