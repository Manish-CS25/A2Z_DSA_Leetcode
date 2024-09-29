class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (n == 1)
            return 0;
        int maxi = INT_MIN;

        stack<int> st;
        st.push(p[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && p[i] >= st.top()) {
                st.pop();
            }
            if (st.empty())
                st.push(p[i]);

            else

                maxi = max(maxi, st.top() - p[i]);
        }

        return maxi>0?maxi:0;
    }
};