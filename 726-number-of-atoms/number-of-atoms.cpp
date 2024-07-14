class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(make_pair("(", -1));
                i++;
            } else if (formula[i] == ')') {
                i++;
                string temp = "";
                while (i < n && formula[i] >= '0' && formula[i] <= '9') {
                    temp += formula[i];
                    i++;
                }
                int digit;
                if (temp.empty()) {
                    digit = 1;
                } else {
                    digit = stoi(temp);
                }
                stack<pair<string, int>> temp_st;
                while (st.top().first != "(") {
                    auto p = st.top();
                    st.pop();
                    p.second *= digit;
                    temp_st.push(p);
                }
                st.pop();
                while (!temp_st.empty()) {
                    st.push(temp_st.top());
                    temp_st.pop();
                }
            } else {
                string s = "";
                s += formula[i];
                i++;
                while (i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                    s += formula[i];
                    i++;
                }
                string num = "";
                while (i < n && formula[i] >= '0' && formula[i] <= '9') {
                    num += formula[i];
                    i++;
                }
                int value;
                if (num.empty()) {
                    value = 1;
                } else {
                    value = stoi(num);
                }
                st.push(make_pair(s, value));
            }
        }

        map<string, int> mp;
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            mp[p.first] += p.second;
        }

        string ans = "";
        for (auto it : mp) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }

        return ans;
    }
};