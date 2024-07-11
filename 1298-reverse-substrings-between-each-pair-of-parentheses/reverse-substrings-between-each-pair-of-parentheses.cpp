class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string str;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(str);
                str = "";
            }
            else if(s[i] == ')'){
                reverse(str.begin(), str.end());
                str = st.top() + str;
                st.pop();
            }else str += s[i];
        }
        return str;
    }
};