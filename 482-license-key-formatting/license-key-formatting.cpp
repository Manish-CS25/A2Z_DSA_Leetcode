class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        int cnt = 0;

        queue<char> q;
        for (char ch : s) {
            if (ch != '-') {
                q.push(toupper(ch)); // Convert to uppercase and push to queue
                cnt++;
            }
        }

        string ans = "";
        int firstGroupSize = cnt % k;

        if (firstGroupSize > 0) {
            for (int i = 0; i < firstGroupSize; ++i) {
                ans += q.front();
                q.pop();
            }
        }
        // Handle the remaining groups
        while (!q.empty()) {
            if (!ans.empty()) {
                ans += '-'; // Add a dash before each new group
            }
            for (int i = 0; i < k; ++i) {
                if (!q.empty()) {
                    ans += q.front();
                    q.pop();
                }
            }
        }

        return ans;

        
    }
};