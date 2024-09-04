class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.size() == 1)
            return 1;
        stack<char> st;
        // st.push(s[0]);

        for (auto it : s) {
            if (!st.empty()) {

                if (st.top() == '(' && it == ')')
                    st.pop();
                else
                    st.push(it);

            } else
                st.push(it);
        }

        return st.size();
    }
};