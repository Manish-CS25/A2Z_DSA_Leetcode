class Solution {
public:
    int minSwaps(string s) {

        int inbalance_cnt = 0;

        int cb = 0;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[')
                st.push(s[i]);

            else if (st.empty())

                inbalance_cnt++;

            else
                st.pop();
        }
        return (inbalance_cnt + 1) / 2;
    }
};

// ==============Optimal Approach================
// class Solution {
// public:
//     int minSwaps(string s) {

//         int inbalance_cnt = 0;

//         int cb = 0;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '[')
//                 cb--;
//             else
//                 cb++;
//             inbalance_cnt = max(cb, inbalance_cnt);
//         }
//         return (inbalance_cnt + 1) / 2;
//     }
// };